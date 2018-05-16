#include "TableForHamster.h"

using namespace std;
TableForHamster::TableForHamster(vector<int> data_of_hamster)
{
	this->dataOfHamster = data_of_hamster;
}
bool TableForHamster::Print_table()
{
	cout << this->dataOfHamster.size() << endl;
	return true;
}
TableForHamster::~TableForHamster()
{
}
