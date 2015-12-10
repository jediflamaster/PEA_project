#include "stdafx.h"
#include <string>
#include <sstream>
using namespace std;


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

void Salesman::load(string name,int towncount)
{
	std::ifstream fil;
	string line;
	string temp;
	int tempnum;
	int count = 0;
	count_of = 4;
	int p = 0;
	int k = 0;
	if (std::string::npos)
	{
		fil.open(name);		
		while (std::getline(fil, line))
		{
			count++;
			std::istringstream iss(line);
			if (count == 4)
			{
				iss >> temp;
				iss >> temp;
				count_of = std::stoi(temp);
				matrix = new int*[count_of];
				for (int i = 0; i < count_of; i++)
					matrix[i] = new int[count_of];
			}
			if (count < 8)
			{
			}
			else
			{
				while (iss >> tempnum)
				{

					//iss >> tempnum;
					matrix[p][k] = tempnum;
					if (k == count_of - 1)
					{
						k = 0;
						p ++;
					}
					else k++;
				}
			}			
		}		
	}
	
	fil.close();
	for (int i = 0; i < count_of; i++)
	{
		for (int j = 0; j < count_of; j++)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}
}
