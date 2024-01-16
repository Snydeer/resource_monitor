#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <psapi.h>
#include "Header.h"


int main() {
	int which;
	double time;

	printf("Type 1 for CPU data\nType 2 for memory data\n");
	scanf("%d", &which);
	printf("How many second would you like to gather data for?\n");
	scanf("%lf", &time);
	plotGraph(which, time);

	return 0;
}





