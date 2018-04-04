#include <iostream>
#include <thread>
#include "Hamster.h"

int main() 
{
	std::cout << "SO2Projekt starting." << std::endl;

	mutex mu;
	vector<vector<int>> table(5, vector<int>(5, 0));

	Hamster hamster(2, 3, 5, table, mu);
	Hamster hamster2(3, 2, 6, table, mu);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	

	system("PAUSE");
	return 0;
}