#include "pch.h"
#include "Header.h"
# include <fstream>
#include <iterator>

extern "C" {

	__declspec(dllexport) SystemTR *create_system(char* filename) {
		ifstream file;
		file.open(filename);
		if (!file.is_open()) {
			perror("File openning error!!!");
			exit(0);
		}
		
		string tmp;
		int key;

		int id;
		string name;
		vector<int> sd;
		int intense[24];
		int Duration_Count;
		vector<int> diractions_id;

		int Transfer_Count;
		vector<int> Transfer_Time;
		vector<int> Transfer_id;

		vector<Line> Lines;
		vector<string> LineNames;
		string LineName;

		int j = 0;

		while (file >> LineName) {
			LineNames.push_back(LineName);
			//cout << LineNames[j] << endl;
			j++;
			Line line;
			while (file >> key) {
				if (key == 1) {
					file >> id >> name >> Duration_Count;
					//cout << id << endl << name << endl << Duration_Count << endl;
					for (int i = 0; i < Duration_Count; i++) {
						int tmp1, tmp2;
						file >> tmp1 >> tmp2;
						diractions_id.push_back(tmp1);
						sd.push_back(tmp2);
						//cout << diractions_id[i] << " " << sd[i] << endl;
					}

					for (int i = 0; i < 24; i++) {
						file >> intense[i];
						//cout << intense[i] << " ";
					}
					//cout << endl << endl;

					RegularStation* temp = new RegularStation(id, name, sd, intense, Duration_Count, diractions_id);
					line.push_back(temp);

					sd.clear();
					diractions_id.clear();

					//list<RegularStation*>::iterator it = line.begin();
					//RegularStation* AAAA = *it;
					//AAAA->printline();
				}
				if (key == 2) {
					file >> id >> name >> Duration_Count;
					//cout << id << endl << name << endl << Duration_Count << endl;
					for (int i = 0; i < Duration_Count; i++) {
						int tmp1, tmp2;
						file >> tmp1 >> tmp2;
						diractions_id.push_back(tmp1);
						sd.push_back(tmp2);
						//cout << diractions_id[i] << " " << sd[i] << endl;
					}

					for (int i = 0; i < 24; i++) {
						file >> intense[i];
						//cout << intense[i] << " ";
					}
					file >> Transfer_Count;
					for (int i = 0; i < Transfer_Count; i++) {
						int tmp1, tmp2;
						file >> tmp1 >> tmp2;
						Transfer_id.push_back(tmp1);
						Transfer_Time.push_back(tmp2);
						//cout << endl << Transfer_id[i] << " " << Transfer_Time[i] << endl;
					}
					//cout << endl << endl;

					RegularStation* temp = new TransferStation(id, name, sd, intense, Duration_Count, diractions_id, Transfer_Count, Transfer_Time, Transfer_id);
					line.push_back(temp);

					//list<RegularStation*>::iterator it = line.begin();
					//RegularStation* AAAA = *it;
					//cout << endl << "Name " << " is: " << AAAA->getName() << endl;

					sd.clear();
					diractions_id.clear();
					Transfer_Time.clear();
					Transfer_id.clear();
				}
				if (key == 0) {
					Lines.push_back(line);
					line.clear();
					break;
				}
			}
		}
		file.close();
		try {
			SystemTR* MYSYSTEM = new SystemTR(Lines, LineNames);
			return MYSYSTEM;
		}
		catch (exception)
		{
			perror("Creating fail :(");
			exit(0);
		}
		
	}
	__declspec(dllexport) int print_AllStations(SystemTR* MYSYSTEM) {

		for (int i = 0; i < MYSYSTEM->Lines.size(); i++) {
			list<RegularStation*>::iterator it = MYSYSTEM->Lines[i].begin();
			for (int j = 0; j < MYSYSTEM->Lines[i].size(); j++) {
				RegularStation* AAAA = *it;
				cout << "id: " << AAAA->get_id() << " name: " << AAAA->getName() << endl;
				++it;
			}
		}
		return 1;
	}

	__declspec(dllexport) int print_station(int number, SystemTR* MYSYSTEM) {

		for (int i = 0; i < MYSYSTEM->Lines.size(); i++) {
			list<RegularStation*>::iterator it = MYSYSTEM->Lines[i].begin();
			for (int j = 0; j < MYSYSTEM->Lines[i].size(); j++) {
				RegularStation* AAAA = *it;
				if (number != AAAA->get_id())
					++it;
				else {
					AAAA->printline();
					return 1;
				}
			}
		}
		cout << "Incorrect id";
		return -1;
	}
	__declspec(dllexport) int print_system(SystemTR* MYSYSTEM) {

		for (int i = 0; i < MYSYSTEM->Lines.size(); i++) {
			list<RegularStation*>::iterator it = MYSYSTEM->Lines[i].begin();
			cout << endl << "Line number "<< i + 1 <<" is "<< MYSYSTEM->LineNames[i] << ":" << endl;
			for (int j = 0; j < MYSYSTEM->Lines[i].size(); j++) {
				RegularStation* AAAA = *it;
				AAAA->printline();
				cout << endl;
					++it;
			}
		}
		return 1;
	}
}