#include "Hamster.h"

Hamster::Hamster(int x, int y, int id, vector<vector<int>>& table, mutex& mut)
{
	mu01 = &mut;
	unique_lock<mutex> locker(*mu01, defer_lock);
	this->id = id;
	this->x = x;
	this->y = y;
	locker.lock();
	table[x][y] = id;
	locker.unlock();
}

bool Hamster::FillWithZeros()
{
	/**table = new int[5];
	for (int i = 0; i < 5; i++)
	{
		table[i] = new int[5];
		fill(table[i], table[i] + 5, 0);
	}*/
	/*for (int i = 0; i < 5; i++)
	{
		for (int j =0; j < 5; j++)
		{
			table[i][j] = 0;
		}
	}*/
	return false;
}

bool Hamster::Move(vector<vector<int>>& table)
{
	unique_lock<mutex> locker(*mu01, defer_lock);

	int direction = rand() % 4;

	if (direction == 0)
	{
		if (x < 4)
		{
			table[x][y] = 0;
			x++;
			table[x][y] = id;
		}
	}
	else if (direction == 1)
	{
		if (y > 0)
		{
			table[x][y] = 0;
			y--;
			table[x][y] = id;
		}
	}
	else if (direction == 2)
	{
		if (x > 0)
		{
			table[x][y] = 0;
			x--;
			table[x][y] = id;
		}
	}
	else if (direction == 3)
	{
		if (y < 4)
		{
			table[x][y] = 0;
			y++;
			table[x][y] = id;
		}
	}

	return true;
}


Hamster::~Hamster()
{
}
