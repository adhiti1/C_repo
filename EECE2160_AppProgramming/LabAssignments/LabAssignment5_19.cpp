// LabAssignment5_19.cpp 
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program uses a function to find max magnitude from 3 integers

#include <iostream>
#include <stdio.h>
#include <math.h>

int MaxMagnitudeOfTwo(int userVal1, int userVal2)
{
    //function returns max of two (just magnitude)
    if (abs(userVal1) > abs(userVal2)) return userVal1; else return userVal2;
}

int MaxMagnitude(int userVal1, int userVal2, int userVal3)
{
    //returns max of 3. Finds max of two and then passes max of that result and 3rd number.
    int maxOfTwo;
    maxOfTwo = MaxMagnitudeOfTwo(userVal1, userVal2);
    return (MaxMagnitudeOfTwo(maxOfTwo, userVal3));
}
int main()
{
    int inpVal1, inpVal2, inpVal3;
    scanf("%d %d %d", &inpVal1, &inpVal2, &inpVal3);
    printf("%d", MaxMagnitude(inpVal1, inpVal2, inpVal3));
}
