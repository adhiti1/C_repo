// LabAssignment6_17.cpp
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program adjusts list by normalizing.

#include <iostream>
#include <stdio.h>

int main()
{
    int numElements;
    double userVals[20];
    double maxValue = 0.0;
    char ch;

    //scan number of input floating point values
    scanf("%d", &numElements);

    //scan double values. Find max of input values.
    for (int i = 0; i <= numElements - 1; i++) {
        scanf("%lf%c", &userVals[i], &ch);
        if (userVals[i] > maxValue) maxValue = userVals[i];

    }

    //output normalized values by dividing by max.
    for (int i = 0; i < numElements; i++) {
        printf("%0.2lf ", userVals[i] / maxValue);
    }

    return 0;
}
