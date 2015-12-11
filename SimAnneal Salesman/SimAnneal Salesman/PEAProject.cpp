

#include "stdafx.h"
#include "generator.h"
#include "targetver.h"
#include "SAsolver.h"


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
void runtest(std::string name)
{
	using namespace std;
	ofstream result;
	SAsolver  testsolver;
	timer mtimer;
	result.open("files//result//" + name + ".txt");
	Salesman * testproblem = new Salesman(name);
	for (double i = 10; i < 100; i *= 2)
	{
		
		for (double j = 0.85; j < 1; j += 0.001)
		{
			result << "Geometric falloff || TSTART: "<< i << " Falloff: "<< j << endl;
			mtimer.start();
			testsolver.solve(i, 0.000001, j, 0, *testproblem);
			mtimer.pause();
			testproblem->printsequence(result);
			result << " ||  Solution: " << testsolver.getsolution() << " time: " << mtimer.getticks() << endl << endl;
		}
		for (double j = 0.1; j > 0.000001; j *= 0.1)
		{
			
			result << "Linear decrement || TSTART: " << i << " Falloff: " << j << endl;
			mtimer.start();
			testsolver.solve(i, 0.000001, 1, j, *testproblem);
			mtimer.pause();
			testproblem->printsequence(result);
			result << " || Solution: " << testsolver.getsolution() << " time: "<< mtimer.getticks() << endl << endl;
		}
		
	}
	result.close();
	delete testproblem;
}
int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	string filename;
	srand(time(NULL));
	cout << "*******************************************************************************\n";
	cout << "**                     Zadanie projektowe nr.1                               **\n";
	cout << "**                 Projektowanie efektywnych algorytmow                      **\n ";
	cout << "*******************************************************************************\n";



	cout << "podaj nazwe pliku"<<endl;
	//runtest("ftv44.atsp");
	cin >> filename;
	cout << "processing"<<endl;
	runtest(filename);
	cout << "done";
	cin >> filename;
	
	return 0;
}

