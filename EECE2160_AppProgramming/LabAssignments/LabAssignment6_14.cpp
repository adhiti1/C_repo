// LabAssignment6_14.cpp
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program outputs number in reverse. It uses arrays

#include <stdio.h>
#include<stdlib.h>

int main()
{
    const int NUM_ELEMENTS = 20;
    int userVals[NUM_ELEMENTS];
    char ch; //space or new line
    int i = 0; //count of elements read
    //read input
    do {
        scanf("%d%c", &userVals[i], &ch);
        i++;
    } while (ch != '\n');

    //print in reverse
    //start from end of array and go back
    for (int j = i - 1; j > 0; j--) {
        printf("%d,", userVals[j]);
    }
    printf("\n");

    return 0;
}

