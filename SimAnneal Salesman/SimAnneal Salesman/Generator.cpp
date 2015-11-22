#include "stdafx.h"


using namespace std;
Generator::Generator()
{
}

void Generator::salesmanSymetry()
{
	int count_of;
	int counter = 1;
	int A[100][100];
	//Count of towns
	/*cout << "Please, enter count of town's:";
	cin >> count_of;*/
	ofstream writer;
	int write_val;
	for (int count_of = 10; count_of <= 100; count_of = count_of + 10)
	{
		for (int number_of_file = 0; number_of_file < 100; number_of_file++)
		{
			//Zeros in table
			for (int i = 0; i < 100; i++)
			{
				for (int j = 0; j < 100; j++)
				{
					A[i][j] = 0;
				}
			}
			writer.open("files//symetry//" + to_string(count_of) + "//" + to_string(number_of_file) + ".txt");
			writer << count_of << endl;
			for (int i = 0; i < count_of; i++)
			{
				for (int j = 0; j < count_of; j++)
				{
					if (i == j) A[i][j] = -1;
					else if (A[j][i] != 0)
					{
						A[i][j] = A[j][i];
					}
					else
					{
						A[i][j] = rand() % 100 + 1;
					}
				}
			}
			for (int i = 0; i < count_of; i++)
			{
				for (int j = 0; j < count_of; j++)
				{
					writer << A[i][j] << "\t";
				}
				writer << endl;
			}
			writer.close();
		}
	}
}



void Generator::salesmanAsymetry()
{
	int count_of;
	int counter = 1;
	int A[100][100];
	//Count of towns
	/*cout << "Please, enter count of town's:";
	cin >> count_of;*/
	ofstream writer;
	int write_val;
	for (int count_of = 10; count_of <= 100; count_of = count_of + 10)
	{
		for (int number_of_file = 0; number_of_file < 100; number_of_file++)
		{
			//Zeros in table
			for (int i = 0; i < 100; i++)
			{
				for (int j = 0; j < 100; j++)
				{
					A[i][j] = 0;
				}
			}
			writer.open("files//asymetry//"+to_string(count_of)+"//" + to_string(number_of_file) + ".txt");
			writer << count_of << endl;
			for (int i = 0; i < count_of; i++)
			{
				for (int j = 0; j < count_of; j++)
				{
					if (i == j) A[i][j] = -1;
					
					else
					{
						A[i][j] = rand() % 100 + 1;
					}
				}
			}
			for (int i = 0; i < count_of; i++)
			{
				for (int j = 0; j < count_of; j++)
				{
					writer << A[i][j] << "\t";
				}
				writer << endl;
			}
			writer.close();
		}
	}
}

Generator::~Generator()
{
}
