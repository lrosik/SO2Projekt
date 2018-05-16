#include <iostream>
#include <time.h>
#include <thread>
#include "Hamster.h"
#include "TableForHamster.h"

using namespace std;

int main() 
{
	srand(time(NULL));

	std::cout << "SO2Projekt starting." << std::endl;

	mutex mut;
	condition_variable cond;
	struct hamsterInTheTable
	{
		vector<int> datOfHamster;
		hamsterInTheTable(vector<int> data_of_hamster)
		{
			this->datOfHamster = data_of_hamster;
		}
		bool Print_table()
		{
			cout << datOfHamster.size() << endl;
			return true;
		}
	};
	vector<vector<TableForHamster>> table_of_hamsters(5, vector<TableForHamster>(5, vector<int>(2, 0)));
	//vector<vector<hamsterInTheTable>> table_of_hamsters(5, vector<hamsterInTheTable>(5, vector<int>(2,0)));
	table_of_hamsters[0][0].Print_table();
	vector<vector<int>> table(5, vector<int>(5, 0));

	Hamster hamster(2, 3, 5, table, mut, cond);
	Hamster hamster2(1, 2, 6, table, mut, cond);
	Hamster hamster3(0, 0, 7, table, mut, cond);
	//Hamster hamster4(0, 1, 8, table, mut, cond);
	//Hamster hamster5(1, 0, 9, table, mut, cond);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << table[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;

	thread t1(&Hamster::MoveCount, &hamster, 10, table);
	thread t2(&Hamster::MoveCount, &hamster2, 10, table);
	thread t3(&Hamster::MoveCount, &hamster3, 10, table);
	cond.notify_one();
	/*for (int i = 0; i < 10; i++)
	{
		
	}*/

	//hamster.Move(table);
	//hamster2.Move(table);
	
	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << table[i][j] << " ";
		}
		cout << endl;
	}*/

	t2.join();
	t1.join();
	t3.join();
	


	system("PAUSE");
	return 0;
}