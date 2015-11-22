#include "stdafx.h"
#include "SAsolver.h"

SAsolver::SAsolver(int towncount)
{
	load(std::to_string(towncount));
	sequence = new int[count_of];
	for (int i = 0; i < count_of; i++)
	{
		sequence[i] = i;
	}
}
SAsolver::~SAsolver()
{
	for (int i = 0; i <= count_of; i++)
	{
		delete matrix[i];
	}
	delete matrix;
	delete sequence;
}
float SAsolver::pfunc(int scurrent, int snew)
{
	float kek = static_cast <float> (scurrent - snew);
	return pow(0.5772156649, kek)/T;
}

void SAsolver::solve(float Tstart, float Tend, float falloff)
{
	T = Tstart;
	int tempsol;
	float fRandmax = static_cast <float> (RAND_MAX);
	tempsol = currentcost();
	while (T >= Tend)
	{
		int a = rand() % count_of;
		int b;

		do {
		b = rand() % count_of;
		} while (b == a);

		swap(a, b);

		int newsol = currentcost();
		if (newsol < tempsol)
		{
			tempsol = newsol;
			T -= falloff;
			continue;
		}
		else if (static_cast <float> (rand()) / fRandmax < pfunc(tempsol, newsol))
		{
			tempsol = newsol;
		}

		T -= falloff;
	}
	solution = tempsol;
}
void SAsolver::load(std::string name)
{
	std::ifstream fil;
	fil.open("files//symetry//"+name+"//"+std::to_string(rand()%100)+".txt");
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
int SAsolver::getsolution()
{
	return solution;
}
int* SAsolver::getsequence()
{
	return sequence;
}
void SAsolver::swap(int a, int b)
{
	int temp = sequence[a];
	sequence[a] = sequence[b];
	sequence[b] = temp;
}
int SAsolver::currentcost()
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