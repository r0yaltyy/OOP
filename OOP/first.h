#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int first();

class RegularStation {
public: 
	string station_name;
	int stage_duration[2];
	int intensity[24];
	
	RegularStation(string name, int sd[2], int intense[24]) {
		this->station_name = name;
		for (int i = 0; i < 2; i++)
			this->stage_duration[i] = sd[i];
		for (int i = 0; i < 24; i++)
			this->intensity[i] = intense[i];
	}
	int operator < (RegularStation second) {
		if (station_name < second.station_name)
			return 1;
		return 0;
	}
	int operator == (RegularStation second) {
		if (station_name == second.station_name)
			return 1;
		return 0;
	}
};