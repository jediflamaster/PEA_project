#pragma once
#include "stdafx.h"


class timer //klasa stopera
{
public:
	timer();
	void start(); //funkcja uruchamiajaca stoper
	void pause(); //funkcja zatrzymuj¹aa stoper
	double getticks(); //funkcja zwracajaca wartosc zmierzona przez stoper
private:
	LARGE_INTEGER startticks;
	LARGE_INTEGER pauseticks;

};



