

#include "stdafx.h"
#include "generator.h"
#include "targetver.h"
#include "SAsolver.h"

using namespace std;
int SAsolve()
{
	ifstream fil;
	//SOME EXAMPLE FROM symetry 0 file
	fil.open("files//symetry//0.txt");
	int count_of;
	fil >> count_of;
	int **B = new int*[count_of];
	for (int i = 0; i < count_of; i++)
		B[i] = new int[count_of];

	for (int i = 0; i < count_of; i++)
	{
		for (int j = 0; j < count_of; j++)
			fil >> B[i][j];
	}
	return 0;
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	cout << "*******************************************************************************\n";
	cout << "**                     Zadanie projektowe nr.1                               **\n";
	cout << "**                 Projektowanie efektywnych algorytmow                      **\n ";
	cout << "*******************************************************************************\n";
	//Generator gen;

	//string file;

	//gen.salesmanAsymetry();
	//gen.salesmanSymetry();
	Salesman * testproblem = new Salesman(10);
	SAsolver  testsolver;

	testsolver.solve(10, 2, 0.1, *testproblem);
	cout << testsolver.getsolution()<< "\n";
	
	system("pause");

	return 0;
}

