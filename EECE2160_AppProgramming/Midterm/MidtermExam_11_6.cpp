// Midterm_11_6.cpp
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program reads four integer input values and a character command
// it then outputs a new value based on the character command.


#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
    int inp1, inp2, inp3, inp4;
    char inpchar;
    char inpCmd;

    double average;
    double sqrdeviationsum;
    double stddev;

    int leftmax, rightmax, maxvalue;

    //get input values
    printf("Enter input vals:");
    scanf("%d %d %d %d%c", &inp1, &inp2, &inp3, &inp4, &inpchar); //capture return otherwise inpcmd will capture it.
    printf("Enter command:");
    scanf("%c", &inpCmd);

    switch (toupper(inpCmd)) {
    case 'A':
        printf("Average: %.3lf", (inp1 + inp2 + inp3 + inp4) * 1.0 / 4.0);
        break;
    case  'S':
        //standard deviation
        average = (inp1 + inp2 + inp3 + inp4) * 1.0 / 4.0;
        sqrdeviationsum = (inp1 - average) * (inp1 - average) + (inp2 - average) * (inp2 - average) + (inp3 - average) * (inp3 - average) + (inp4 - average) * (inp4 - average);
        stddev = sqrt(sqrdeviationsum / 4.0);
        printf("Standard Deviation: %.3lf", stddev);
        break;
    case 'M':
        //find max of two pairs and then find max of resulting value.
        if (inp1 > inp2) leftmax = inp1; else leftmax = inp2;
        if (inp3 > inp4) rightmax = inp3; else rightmax = inp4;
        if (leftmax > rightmax) maxvalue = leftmax; else maxvalue = rightmax;
        printf("Maximum value: %d", maxvalue);
        break;
    default:
        printf("Invalid Command %c", inpCmd);
        break;
    }
    return 0;
}

