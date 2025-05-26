// LabAssignment_5_17.cpp 
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program uses a function to convert laps to to miles

#include <iostream>
#include <stdio.h>


double LapsToMiles(double userLaps)
{
    //one lap is exactly 0.25 miles
    return userLaps * 0.25;
}

int main()
{
    double inpLaps;

    scanf("%lf", &inpLaps);
    printf("%0.2lf\n", LapsToMiles(inpLaps));
}
