#pragma once
#include <windows.h>
#include <psapi.h>
#include <stdio.h>
#include <stdlib.h>

void mkBothData(int x);
double Netuage();
double getCPUpercentage();
static float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks);
static unsigned long long FileTimeToInt64(const FILETIME* ft);
float GetCPULoad();
double getMEMpercentage(int num);
int plotGraph();
