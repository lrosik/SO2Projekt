#include "Hamster.h"

Hamster::Hamster(int x, int y, int id, vector<vector<int>>& table, mutex& mut)
{
	mu = &mut;
	unique_lock<mutex> locker(*mu, defer_lock);
	this->id = id;
	this->x = x;
	this->y = y;
	locker.lock();
	table[x][y] = id;
	locker.unlock();
}

bool Hamster::FillWithZeros()
{
	return false;
}

bool Hamster::Move(vector<vector<int>>& table)
{
	unique_lock<mutex> locker(*mu, defer_lock);

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

void Hamster::MoveCount(int count, vector<vector<int>>& table)
{
	unique_lock<mutex> locker(*mu, defer_lock);
	for (int i = 0; i < count; i++)
	{
		locker.lock();
		Move(table);
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << table[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << id << endl;
		cout << endl;
		locker.unlock();
	}
}


Hamster::~Hamster()
{
}
