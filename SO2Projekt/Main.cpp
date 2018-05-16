#include <iostream>
#include <time.h>
#include <thread>
#include "Hamster.h"
#include "TableForHamster.h"

using namespace std;
condition_variable cond;
mutex mut;
void func(vector<Hamster> &hamsters, thread *threads)
{
	cout << "1";
	while (hamsters[0].number_of_hamsters != 0)
	{
		unique_lock<mutex> locker(mut, defer_lock);
		//locker.lock();
		//cond.wait(locker);
		cout << "2";
		if (hamsters[0].number_of_hamsters == 1)
		{
			cout << "3";
			for (int i = 0; i < 5; i++)
			{
				if (threads[i].joinable())
				{
					cond.notify_one();
				}
			}
			//cout << "3";
			//threads[0].detach();
			//threads[1].detach();
			//threads[2].detach();
			//threads[3].detach();
			//threads[4].detach();
			////threads[0].~thread();
			////threads[1].~thread();
			////threads[2].~thread();
			////threads[3].~thread();
			////threads[4].~thread();
			////cond.notify_one();
			//return;
		}
		//locker.unlock();
		//cond.notify_one();
		this_thread::sleep_for(chrono::milliseconds(200));
	}
	cout << hamsters[0].number_of_hamsters;
}
int main() 
{
	srand(time(NULL));

	std::cout << "SO2Projekt starting." << std::endl;
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
	//vector<vector<int>> table(5, vector<int>(5, 0));
	vector<thread> threads;
	vector<Hamster> hamsters;
	Hamster hamster(1, 0, 0, 5, table_of_hamsters, mut, cond, threads);
	Hamster hamster2(1, 0, 1, 6, table_of_hamsters, mut, cond, threads);
	Hamster hamster3(1, 1, 0, 7, table_of_hamsters, mut, cond, threads);
	Hamster hamster4(1, 1, 1, 8, table_of_hamsters, mut, cond, threads);
	Hamster hamster5(1, 0, 2, 9, table_of_hamsters, mut, cond, threads);
	hamsters.push_back(Hamster(1, 0, 0, 5, table_of_hamsters, mut, cond, threads));
	hamsters.push_back(Hamster(1, 0, 1, 6, table_of_hamsters, mut, cond, threads));
	hamsters.push_back(Hamster(1, 1, 0, 7, table_of_hamsters, mut, cond, threads));
	hamsters.push_back(Hamster(1, 1, 1, 8, table_of_hamsters, mut, cond, threads));
	hamsters.push_back(Hamster(1, 0, 2, 9, table_of_hamsters, mut, cond, threads));
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
	thread *threads1 = new thread[5];
	//vector <thread> threads
	thread Dajciemijuzspokoj = thread(func, hamsters, threads1);
	threads1[0] = thread(&Hamster::NewMoveCount, &hamster, 10);
	threads1[1] = thread(&Hamster::NewMoveCount, &hamster2, 10);
	threads1[2] = thread(&Hamster::NewMoveCount, &hamster3, 10);
	threads1[3] = thread(&Hamster::NewMoveCount, &hamster4, 10);
	threads1[4] = thread(&Hamster::NewMoveCount, &hamster5, 10);
	//threads.push_back(thread(&Hamster::NewMoveCount, &hamster, 10));
	//threads.push_back(t2);
	//threads.push_back(t3);
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
	//Dajciemijuzspokoj.join();
	threads1[0].join();
	threads1[1].join();
	threads1[2].join();
	threads1[3].join();
	threads1[4].join();
	//Dajciemijuzspokoj.detach();
	//Dajciemijuzspokoj.join();
	system("PAUSE");
	return 0;
}