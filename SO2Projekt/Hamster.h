#pragma once
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
using namespace std;

class Hamster
{
	static const int size = 5;
	static once_flag flag_01;
	int id, x, y;
public:
	mutex* mu01 = nullptr;
	Hamster(int x, int y, int id, vector<vector<int>>& table, mutex& mut);
	bool FillWithZeros();
	bool Move();
	~Hamster();
};

