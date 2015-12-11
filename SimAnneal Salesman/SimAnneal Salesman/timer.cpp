#include "stdafx.h"
#include "timer.h"

using namespace std;


timer::timer()
{

}
void timer::start()
{
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&startticks);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
}
void timer::pause()
{
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&pauseticks);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
}
double timer::getticks()
{
	return (pauseticks.QuadPart - startticks.QuadPart);
}
