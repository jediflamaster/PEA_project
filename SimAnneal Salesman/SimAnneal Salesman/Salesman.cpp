#include "stdafx.h"



Salesman::Salesman(int towncount)
{
	load(towncount);
	sequence = new int[count_of];
	for (int i = 0; i < count_of; i++)
	{
		sequence[i] = i;
	}
}


Salesman::~Salesman()
{
	for (int i = 0; i < count_of; i++)
	{

		delete[] matrix[i];

	}
	delete[] matrix;

}
int Salesman::getcount()
{

	return count_of;
}
int Salesman::currentcost()
{
	int costsum = 0;
	count_of--;
	for (int i = 0; i < count_of; i++)
	{
		costsum += matrix[sequence[i]][sequence[i + 1]];

	}

	costsum += matrix[sequence[count_of]][sequence[0]];
	count_of++;
	return costsum;
}
void Salesman::swap(int a, int b)
{
	int temp = sequence[a];
	sequence[a] = sequence[b];
	sequence[b] = temp;
}

int Salesman::getsequence(int index)
{
	return sequence[index];
}

void Salesman::load(int towncount)
{
	std::ifstream fil;
	fil.open("files//symetry//" +std::to_string(towncount) + "//" + std::to_string(rand() % 100) + ".txt");
	fil >> count_of;
	matrix = new int*[count_of];
	for (int i = 0; i < count_of; i++)
		matrix[i] = new int[count_of];

	for (int i = 0; i < count_of; i++)
	{
		for (int j = 0; j < count_of; j++)
			fil >> matrix[i][j];
	}
	fil.close();
}