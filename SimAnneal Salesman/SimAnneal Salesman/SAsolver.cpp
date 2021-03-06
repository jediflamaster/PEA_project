#include "stdafx.h"


SAsolver::SAsolver()
{

}
SAsolver::~SAsolver()
{

}
double SAsolver::pfunc(int scurrent, int snew)
{
	double kek = static_cast <double> (scurrent - snew);
	return (pow(2.718281828, kek) / T);
}

void SAsolver::solve(double Tstart, double Tend, double fallofffactor, double decrement, Salesman &problemref)
{
	T = Tstart;
	int tempsol;
	double fRandmax = static_cast <double> (RAND_MAX);
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
		
	
		}
		else 
		{
			if ((static_cast <double> (rand())) / fRandmax < pfunc(tempsol, newsol))
			{
				tempsol = newsol;
			}
			else
			{
				problemref.swap(a, b);
			}
			
		}

		T = T*fallofffactor - decrement;
	}
	solution = tempsol;
}

int SAsolver::getsolution()
{
	return solution;
}

