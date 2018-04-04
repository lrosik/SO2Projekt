#include "Hamster.h"

Hamster::Hamster(int x, int y, int id)
{
	unique_lock<mutex> locker(mu_01, defer_lock);
	this->id = id;
	this->x = x;
	this->y = y;
	locker.lock();
	FillWithZeros();
	table[x][y] = id;
	locker.unlock();
}

bool Hamster::FillWithZeros()
{
	table = new vector<vector<int>>(5, vector<int>(5, 0));
	return false;
}

bool Hamster::Move()
{
	unique_lock<mutex> locker(mu_01, defer_lock);
	if (x > size / 2)
	{
		locker.lock();
		//if(table)
	}
	return true;
}


Hamster::~Hamster()
{
}
