#include "Hamster.h"
#include "TableForHamster.h"

int Hamster::number_of_hamsters = 5;
Hamster::Hamster(int x, int y, int id, vector<vector<int>>& table, mutex& mut, condition_variable& condition, vector<thread>& threads)
{
	mu = &mut;
	cond = &condition;
	unique_lock<mutex> locker(*mu, defer_lock);
	this->id = id;
	this->x = x;
	this->y = y;
	locker.lock();
	table[x][y] = id;
	this->threads = &threads;
	locker.unlock();
}

Hamster::Hamster(int lvl, int x, int y, int id, vector<vector<TableForHamster>>& tableH, mutex& mut, condition_variable& condition, vector<thread>& threads)
{
	mu = &mut;
	cond = &condition;
	unique_lock<mutex> locker(*mu, defer_lock);
	this->lvl = lvl;
	this->id = id;
	this->x = x;
	this->y = y;
	locker.lock();
	this->table = &tableH;
	tableH[x][y] = TableForHamster({ id,lvl });
	this->threads = &threads;
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

//bool Hamster::MoveOnNewTable(vector<vector<TableForHamster>>& table)
bool Hamster::MoveOnNewTable()
{
	unique_lock<mutex> locker(*mu, defer_lock);

	int direction = rand() % 4;

	if (direction == 0)
	{
		//if (x < 4 && table[x + 1][y].GetID() == 0)
		if (x < 4)
		{
			if ((*table)[x + 1][y].GetID() != 0)
			{
				Die();
				(*table)[x][y].SetID(0);
				this->id = 0;
			}
			else
			{
				(*table)[x][y].SetID(0);// = 0;
				x++;
				(*table)[x][y].SetID(id);
			}
		}
	}
	else if (direction == 1)
	{
		//if (y > 0 && table[x][y - 1].GetID() == 0)
		if (y > 0)
		{
			if ((*table)[x][y - 1].GetID() != 0)
			{
				Die();
				(*table)[x][y].SetID(0);
				this->id = 0;
			}
			else
			{
				(*table)[x][y].SetID(0);
				y--;
				(*table)[x][y].SetID(id);
			}
		}
	}
	else if (direction == 2)
	{
		//if (x > 0 && table[x - 1][y].GetID() == 0)
		if (x > 0)
		{
			if ((*table)[x - 1][y].GetID() != 0)
			{
				Die();
				(*table)[x][y].SetID(0);
				this->id = 0;
			}
			else
			{
				(*table)[x][y].SetID(0);
				x--;
				(*table)[x][y].SetID(id);
			}
		}
	}
	else if (direction == 3)
	{
		//if (y < 4 && table[x][y + 1].GetID() == 0)
		if (y < 4)
		{
			if ((*table)[x][y + 1].GetID() != 0)
			{
				Die();
				(*table)[x][y].SetID(0);
				this->id = 0;
			}
			else
			{
				(*table)[x][y].SetID(0);
				y++;
				(*table)[x][y].SetID(id);
			}
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

//void Hamster::NewMoveCount(int count, vector<vector<TableForHamster>>& table)
void Hamster::NewMoveCount(int count)
{
	
	unique_lock<mutex> locker(*mu, defer_lock);
	for (int i = 0; i < count; i++)
	{
		if (!isLiving)
		{
			cond->notify_one();
			return;
		}
		//this_thread::sleep_for(chrono::milliseconds(500));
		locker.lock();
		cond->wait(locker);
		//MoveOnNewTable(table);
		MoveOnNewTable();
		clear_screen(' ');
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				//cout << table[i][j] << " ";
				(*table)[i][j].Print_table();
				cout << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << id << endl;
		cout << number_of_hamsters << endl;
		cout << endl;
		this_thread::sleep_for(chrono::milliseconds(200));
		locker.unlock();
		cond->notify_one();
	}
	Die();
	cond->notify_one();
}

bool Hamster::KillHamsta(int ID)
{
	int i = 0;
	while (i < threads->size())
	{
		/*if (threads[i].get_id() == i)
		{
			threads[i].~thread();
			return true;
		}*/
		i++;
	}
	return false;
}

bool Hamster::SetId(int ID)
{
	this->id = ID;
	return true;
}

bool Hamster::Die()
{
	this->isLiving = false;
	number_of_hamsters -= 1;
	return true;
}

void Hamster::clear_screen(char fill) {
	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}

Hamster::~Hamster()
{
}
