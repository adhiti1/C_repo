// LabAssignment6_15.cpp 
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program outputs the middle integer given sorted list of integers
// assume number of integers is always odd
// -ve number indicates end of input.


#include <stdio.h>

int main()
{
    const int NUM_ELEMENTS = 9;
    int userValues[NUM_ELEMENTS];
    int inpVal = 0, i = 0;
    char ch;


    //read input. Exit loop if you get a negative number.
    //do not store negative number.
    do {
        scanf("%d%c", &inpVal, &ch);
        if (inpVal > 0) {
            userValues[i] = inpVal;
            i++;
        }
    } while (inpVal > 0);

    //print middle item. Dividing an odd integer will return quotient which will be middle item.

    printf("Middle item: %d", userValues[i / 2]);
    return 0;
}
