#include <windows.h>
#include <psapi.h>
#include <stdio.h>



double getMEMpercentage(int num)
{
    MEMORYSTATUSEX memoryStatus;
    memoryStatus.dwLength = sizeof(memoryStatus);
    GlobalMemoryStatusEx(&memoryStatus);

    double TMEM = memoryStatus.ullTotalPhys;
    double MEM = memoryStatus.ullAvailPhys;
    double MEMpercentage = memoryStatus.dwMemoryLoad;
    double MEMInUse = TMEM- MEM;
    MEMInUse = MEMInUse / 1024 / 1024 /1024;

    if (num == 1) {
        return MEMpercentage;
    }
    else { return MEMInUse; }
}

