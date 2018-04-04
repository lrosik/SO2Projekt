#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
using namespace std;

class Hamster
{
	static const int size = 5;
	static once_flag flag_01;
	mutex *mu;
	int id, x, y;
public:
	Hamster(int x, int y, int id, vector<vector<int>>& table, mutex& mut);
	bool FillWithZeros();
	bool Move(vector<vector<int>>& table);
	void MoveCount(int count, vector<vector<int>>& table);
	~Hamster();
};

