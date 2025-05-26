// LabAssignment5_18.cpp 
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program uses a function to find driving costs.

#include <iostream>
#include <stdio.h>

double DrivingCost(double milesPerGallon, double dollarsperGallon, double milesDriven)
{
    //returns cost
    return ((milesDriven / milesPerGallon) * dollarsperGallon);
}
int main()
{
    double milesPerGallon, dollarsPerGallon;

    scanf("%lf %lf", &milesPerGallon, &dollarsPerGallon);
    //cost for 10, 50, 400 miles
    printf("%0.2lf %0.2lf %0.2lf", DrivingCost(milesPerGallon, dollarsPerGallon, 10), DrivingCost(milesPerGallon, dollarsPerGallon, 50), DrivingCost(milesPerGallon, dollarsPerGallon, 400));
}
