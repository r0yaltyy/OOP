#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;
int first() {
	srand((int)time(NULL));
		string str = "Maximova";
		string str2 = "Kurch";
		int dur[2], intense[24];
		int dur2[2], intense2[24];
		for (int i = 0; i < 2; i++)
			dur[i] = 5 + (rand() % 20);
		for (int i = 0; i < 24; i++)
				intense[i] = 10 + (rand() % 15);

		for (int i = 0; i < 2; i++)
			dur2[i] = 5 + (rand() % 20);
		for (int i = 0; i < 24; i++)
			intense2[i] = 10 + (rand() % 15);


		RegularStation TEST = RegularStation(str, dur, intense);
		RegularStation TEST2 = RegularStation(str2, dur2, intense);
		//проверяем работу операторов
		if (TEST2 < TEST)
			cout << "haha1" << endl;
		if (TEST < TEST2)
			cout << "haha2" << endl;
		if (TEST == TEST2)
			cout << "haha3" << endl;
		if (!(TEST == TEST2))
			cout << "haha4" << endl;

		return 0;
}