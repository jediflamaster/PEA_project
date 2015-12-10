#pragma once
#include "stdafx.h"
class Salesman
{
private:
	int **matrix;
	int * sequence;
	int count_of;
public:
	void load(string name);
	void swap(int, int);
	int currentcost();
	int getsequence(int index);
	int getcount();
	Salesman(int);
	~Salesman();
	int *operator[](int el) { return matrix[el]; }
};
