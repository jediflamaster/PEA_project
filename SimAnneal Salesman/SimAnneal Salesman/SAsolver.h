#pragma once

#include "stdafx.h"

class SAsolver {
private:

	int solution;
	double T;

public:
	double pfunc(int, int);
	SAsolver();
	~SAsolver();
	void solve(double Tstart, double Tend, double falloff, Salesman &problemref);
	void load(std::string);
	int getsolution();
};