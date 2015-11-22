#pragma once

#include "stdafx.h"

class SAsolver {
private:

	int solution;
	int *sequence;
	int count_of;
	int ** matrix;
	float T;

public:
	float pfunc(int, int);
	SAsolver(int towncount);
	~SAsolver();
	void solve(float Tstart, float Tend, float falloff);
	void load(std::string);
	int getsolution();
	int* getsequence();
	void swap(int, int);
	int currentcost();
};