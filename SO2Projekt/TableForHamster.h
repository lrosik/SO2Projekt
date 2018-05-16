#pragma once
#include <mutex>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class TableForHamster
{
	vector<int> dataOfHamster;
public:
	TableForHamster(vector<int> data_of_hamster);
	int GetID();
	bool SetID(int ID);
	int GetLvl();
	bool SetLvl(int ID);
	bool LvlUP();
	bool Print_table();
	~TableForHamster();
};

