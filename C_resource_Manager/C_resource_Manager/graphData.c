#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "Header.h"

//#include "C:\Program Files\gnuplot\bin\gnuplot"



int plotGraph(int which, double time)
{   
    printf("%lf", time);
    time *= 4.0;
    double dat;
    char* commandsForGnuplot[] = { "set title \"Data\"", "plot 'data.temp' linetype 7 with linespoints " };
    FILE* temp = fopen("data.temp", "w");
    /*Opens an interface that one can use to send commands as if they were typing into the
     *     gnuplot command line.  "The -persistent" keeps the plot open even after your
     *     C program terminates.
     */
    FILE* gnuplotPipe = _popen("gnuplot -persistent", "w");
    //time *4 because will print a a data point once every .25 seconds
    for (double i = 0.0; i < time; i++)
    {
        //if which is equal to 1 then print the CPU graph
        if (which == 1) {
            dat = getCPUpercentage();
        }
        else if ((which == 2)) {
            dat = getMEMpercentage(1);
        }
        else if (which == 3) {
            //dat = getNetusage();
        }
        else {
            return 0;
        }
        
        Sleep(250);
        printf("%lf  %lf \n", i, dat);
        fprintf(temp, "%lf  %lf \n", i, dat); //Write the data to a temporary file
        fflush(temp);
        fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[1]); //Send commands to gnuplot one by one.
        fflush(gnuplotPipe);
        
    }

    
    
    
       
}




