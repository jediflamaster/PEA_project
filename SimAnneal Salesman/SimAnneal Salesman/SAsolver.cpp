#include "stdafx.h"


SAsolver::SAsolver()
{

}
SAsolver::~SAsolver()
{

}
float SAsolver::pfunc(int scurrent, int snew)
{
	float kek = static_cast <float> (scurrent - snew);
	return pow(0.5772156649, kek)/T;
}

void SAsolver::solve(float Tstart, float Tend, float falloff, Salesman &problemref)
{
	T = Tstart;
	int tempsol;
	float fRandmax = static_cast <float> (RAND_MAX);
	tempsol = problemref.currentcost();
	while (T >= Tend)
	{
		int a = rand() % problemref.getcount();
		int b;

		do {
			b = rand() % problemref.getcount();
		} while (b == a);

		problemref.swap(a, b);

		int newsol = problemref.currentcost();
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

int SAsolver::getsolution()
{
	return solution;
}

