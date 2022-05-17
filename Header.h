#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;


class RegularStation {

private:
	int id;
	string station_name;
	int duration_count;
	vector <int> diractions_id;
	vector <int> stage_duration;
	int intensity[24];
public:

	RegularStation(int id, string name, vector <int> sd, int intense[24], int Duration_Count, vector<int> diractions_id) {
		this->id = id;
		this->station_name = name;
		this->duration_count = Duration_Count;
		for (int i = 0; i < duration_count; i++) {
			this->stage_duration.push_back(sd[i]);
			this->diractions_id.push_back(diractions_id[i]);
		}
		for (int i = 0; i < 24; i++)
			this->intensity[i] = intense[i];
	}
	~RegularStation() {};

	string getName() {
		return this->station_name;
	}
	int GetDurCount() {
		cout << this->duration_count;
		return this->duration_count;
	}
	virtual vector<int> getTransfers() {
		cout << this->diractions_id[0] << endl;
		return this->diractions_id;
	}
	int operator < (RegularStation second) {
		return (station_name < second.station_name);
	}
	int operator == (RegularStation second) {
		return (station_name == second.station_name);
	}
	int get_id() {
		return this->id;
	}
	virtual void printline() {
		cout << endl << "Station number: " << id << " is " << station_name << endl;
		cout << "Diractions:" << endl;
		for (int i = 0; i < duration_count; i++) {
			cout << "To station " << diractions_id[i] << ". Time of duration:" << stage_duration[i] << " minutes" << endl;
		}
		cout << "Intensity of trains:" << endl;
		for (int i = 0; i < 24; i++)
			
			cout <<"At " << i+1 <<" o'clock trains walks every " << intensity[i] << " minutes" << endl;
	}
};

class TransferStation : public RegularStation {

private:
	int TransferCount;
	vector<int> TransferTime;
	vector<int> Transfer_id;
public:
	TransferStation(int id, string name, vector<int> sd, int intense[24], int Duration_Count, vector<int> diractions_id, int Transfer_Count, vector<int> Transfer_Time, vector<int> Transfer_id)
		:RegularStation(id, name, sd, intense, Duration_Count, diractions_id) {
		this->TransferCount = Transfer_Count;
		for (int i = 0; i < Transfer_Count; i++) {
			this->TransferTime.push_back(Transfer_Time[i]);
			this->Transfer_id.push_back(Transfer_id[i]);
		}
	}
	virtual vector<int> getTransfers() {
		vector<int> fullTr = RegularStation::getTransfers();
		fullTr.insert(fullTr.end(), Transfer_id.begin(), Transfer_id.end());
		cout << fullTr[0] << endl;
		return fullTr;
	}
	virtual void printline() {
		RegularStation::printline();
		cout << "Transfers:" << endl;
		for (int i = 0; i < TransferCount; i++) {
			cout << "To station " << Transfer_id[i] << " time of transfer: " << TransferTime[i] << " minutes" << endl;
		}
	}
};

typedef list<RegularStation*> Line;

class SystemTR {
public:
	vector<Line> Lines;
	vector<string> LineNames;

	SystemTR(vector<Line> Lines, vector<string> LineNames) {
		this->Lines = Lines;
		this->LineNames = LineNames;
	}

	int GetTrip() {
		return 0;
	}
};