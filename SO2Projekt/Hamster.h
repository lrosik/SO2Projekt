#pragma once
#include <mutex>
#include <vector>
using namespace std;
class Hamster
{
	const static int size = 5;
	static vector<vector<int>> table;// (5, vector<int>(5, 0));
	static mutex mu_01;
	static once_flag flag_01;
	int id, x, y;
public:
	Hamster(int x, int y, int id);
	bool FillWithZeros(int i);
	bool Move();
	~Hamster();
};

