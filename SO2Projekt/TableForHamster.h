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
	bool Print_table();
	~TableForHamster();
};

