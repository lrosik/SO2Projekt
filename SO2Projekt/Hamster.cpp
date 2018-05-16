#include "Hamster.h"
#include "TableForHamster.h"

Hamster::Hamster(int x, int y, int id, vector<vector<int>>& table, mutex& mut, condition_variable& condition)
{
	mu = &mut;
	cond = &condition;
	unique_lock<mutex> locker(*mu, defer_lock);
	this->id = id;
	this->x = x;
	this->y = y;
	locker.lock();
	table[x][y] = id;
	locker.unlock();
}

Hamster::Hamster(int lvl, int x, int y, int id, vector<vector<TableForHamster>>& table, mutex& mut, condition_variable& condition)
{
	mu = &mut;
	cond = &condition;
	unique_lock<mutex> locker(*mu, defer_lock);
	this->lvl = lvl;
	this->id = id;
	this->x = x;
	this->y = y;
	locker.lock();
	table[x][y] = TableForHamster({ id,lvl });
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
		if (x < 4 && table[x+1][y] == 0)
		{
			table[x][y] = 0;
			x++;
			table[x][y] = id;
		}
	}
	else if (direction == 1)
	{
		if (y > 0 && table[x][y-1] == 0)
		{
			table[x][y] = 0;
			y--;
			table[x][y] = id;
		}
	}
	else if (direction == 2)
	{
		if (x > 0 && table[x - 1][y] == 0)
		{
			table[x][y] = 0;
			x--;
			table[x][y] = id;
		}
	}
	else if (direction == 3)
	{
		if (y < 4 && table[x][y+1] == 0)
		{
			table[x][y] = 0;
			y++;
			table[x][y] = id;
		}
	}

	return true;
}

bool Hamster::MoveOnNewTable(vector<vector<TableForHamster>>& table)
{
	unique_lock<mutex> locker(*mu, defer_lock);

	int direction = rand() % 4;

	if (direction == 0)
	{
		if (x < 4 && table[x + 1][y].GetID() == 0)
		{
			table[x][y].SetID(0);// = 0;
			x++;
			table[x][y].SetID(id);
		}
	}
	else if (direction == 1)
	{
		if (y > 0 && table[x][y - 1].GetID() == 0)
		{
			table[x][y].SetID(0);
			y--;
			table[x][y].SetID(id);
		}
	}
	else if (direction == 2)
	{
		if (x > 0 && table[x - 1][y].GetID() == 0)
		{
			table[x][y].SetID(0);
			x--;
			table[x][y].SetID(id);
		}
	}
	else if (direction == 3)
	{
		if (y < 4 && table[x][y + 1].GetID() == 0)
		{
			table[x][y].SetID(0);
			y++;
			table[x][y].SetID(id);
		}
	}

	return true;
}

void Hamster::MoveCount(int count, vector<vector<int>>& table)
{
	unique_lock<mutex> locker(*mu, defer_lock);
	for (int i = 0; i < count; i++)
	{
		//this_thread::sleep_for(chrono::milliseconds(500));
		locker.lock();
		cond->wait(locker);
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
		cond->notify_one();
	}
	cond->notify_one();
}

void Hamster::NewMoveCount(int count, vector<vector<TableForHamster>>& table)
{
	unique_lock<mutex> locker(*mu, defer_lock);
	for (int i = 0; i < count; i++)
	{
		//this_thread::sleep_for(chrono::milliseconds(500));
		locker.lock();
		cond->wait(locker);
		MoveOnNewTable(table);
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				//cout << table[i][j] << " ";
				table[i][j].Print_table();
				cout << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << id << endl;
		cout << endl;
		locker.unlock();
		cond->notify_one();
	}
	cond->notify_one();
}


Hamster::~Hamster()
{
}
