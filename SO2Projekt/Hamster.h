#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include "TableForHamster.h"
using namespace std;

class Hamster
{
	static const int size = 5;
	static once_flag flag_01;
	mutex *mu;
	condition_variable *cond;
	int id, x, y, lvl;
	bool isLiving = true;
	vector<thread> *threads;
	vector<vector<TableForHamster>> *table;
public:
	Hamster(int x, int y, int id, vector<vector<int>>& table, mutex& mut, condition_variable& condition, vector<thread>& threads);
	Hamster(int lvl, int x, int y, int id, vector<vector<TableForHamster>>& tableH, mutex& mut, condition_variable& condition, vector<thread>& threads);
	bool FillWithZeros();
	bool Move(vector<vector<int>>& table);
	bool MoveOnNewTable();
	//bool MoveOnNewTable(vector<vector<TableForHamster>>& table);
	void MoveCount(int count, vector<vector<int>>& table);
	//void NewMoveCount(int count, vector<vector<TableForHamster>>& table);
	void NewMoveCount(int count);
	bool KillHamsta(int ID);
	bool SetId(int ID);
	bool Die();
	void clear_screen(char fill);
	~Hamster();
};

