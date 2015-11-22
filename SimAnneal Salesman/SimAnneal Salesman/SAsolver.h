#pragma once

#include "stdafx.h"

class SAsolver {
private:

	int solution;
	float T;

public:
	float pfunc(int, int);
	SAsolver();
	~SAsolver();
	void solve(float Tstart, float Tend, float falloff, Salesman &problemref);
	void load(std::string);
	int getsolution();
};