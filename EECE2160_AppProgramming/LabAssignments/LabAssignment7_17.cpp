// LabAssignment7_17.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program count input length without spaces, periods, exclamation points, or commas


#include <iostream>
#include <stdio.h>
#include<string.h>

int main()
{
    char inpString[2000];
    int charCount = 0;

    scanf("%[^\n]s", &inpString);

    for (int i = 0; i <= strlen(inpString); i++) {
        if (inpString[i] != ' ' && inpString[i] != '.' && inpString[i] != '!' && inpString[i] != ',' && inpString[i] != '\n' && inpString[i] != '\0') {
            charCount++;
            printf("%c\n", inpString[i]);
        }
    }

    printf("%d\n", charCount);

    return 0;
}
