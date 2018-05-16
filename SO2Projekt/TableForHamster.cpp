#include "TableForHamster.h"

using namespace std;
TableForHamster::TableForHamster(vector<int> data_of_hamster)
{
	this->dataOfHamster = data_of_hamster;
}
int TableForHamster::GetID()
{
	return dataOfHamster[0];
}
bool TableForHamster::SetID(int ID)
{
	this->dataOfHamster[0] = ID;
	return true;
}
int TableForHamster::GetLvl()
{
	return dataOfHamster[1];
}
bool TableForHamster::SetLvl(int lvl)
{
	this->dataOfHamster[1] = lvl;
	return true;
}
bool TableForHamster::LvlUP()
{
	this->dataOfHamster[1]++;
	return true;
}
bool TableForHamster::Print_table()
{
	cout << this->dataOfHamster[0];// << endl;
	return true;
}
TableForHamster::~TableForHamster()
{
}
