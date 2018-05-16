#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
#include "TableForHamster.h"
using namespace std;

class Hamster
{
	static const int size = 5;
	static once_flag flag_01;
	mutex *mu;
	condition_variable *cond;
	int id, x, y, lvl;
public:
	Hamster(int x, int y, int id, vector<vector<int>>& table, mutex& mut, condition_variable& condition);
	Hamster(int lvl, int x, int y, int id, vector<vector<TableForHamster>>& table, mutex& mut, condition_variable& condition);
	bool FillWithZeros();
	bool Move(vector<vector<int>>& table);
	void MoveCount(int count, vector<vector<int>>& table);
	~Hamster();
};

