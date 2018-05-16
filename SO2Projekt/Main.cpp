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
	/*struct hamsterInTheTable
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
	};*/
	vector<vector<TableForHamster>> table_of_hamsters(5, vector<TableForHamster>(5, vector<int>(2, 0)));
	//vector<vector<hamsterInTheTable>> table_of_hamsters(5, vector<hamsterInTheTable>(5, vector<int>(2,0)));
	table_of_hamsters[0][0].Print_table();
	//vector<vector<int>> table(5, vector<int>(5, 0));
	vector<thread> threads;
	Hamster hamster(1, 2, 3, 5, table_of_hamsters, mut, cond, threads);
	Hamster hamster2(1, 1, 2, 6, table_of_hamsters, mut, cond, threads);
	Hamster hamster3(1, 0, 0, 7, table_of_hamsters, mut, cond, threads);
	//Hamster hamster4(0, 1, 8, table, mut, cond);
	//Hamster hamster5(1, 0, 9, table, mut, cond);

	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		table_of_hamsters[i][j].Print_table();
	//		cout << " ";
	//		//cout << table[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	cout << endl;
	cout << endl;

	thread t1(&Hamster::NewMoveCount, &hamster, 10, table_of_hamsters);
	thread t2(&Hamster::NewMoveCount, &hamster2, 12, table_of_hamsters);
	thread t3(&Hamster::NewMoveCount, &hamster3, 10, table_of_hamsters);
	threads.push_back(t1);
	threads.push_back(t2);
	threads.push_back(t3);
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