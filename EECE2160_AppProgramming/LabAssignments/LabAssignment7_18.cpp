// LabAssignment7_18.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program prints string in reverse.

#include <iostream>
#include <stdio.h>
#include <string.h>


void printReverse(char paramString[], int length) {
    for (int i = length; i >= 0; i--) {
        printf("%c", paramString[i]);
    }
    //printf("\n");
}
int main()
{
    char inpString[50];
    int length;
    char String[2000] = "";
    do
    {
        fgets(inpString, 50, stdin);
        if (strcmp(inpString, "done\n") != 0 && strcmp(inpString, "d\n") != 0 && strcmp(inpString, "Done\n") != 0)
        {
            //remove newline
            length = 0;
            for (int i = 0; i <= strlen(inpString) - 1; i++) {
                if (inpString[i] != '\n')
                    length++;
                else if (inpString[i] == '\n')
                    break;
            }
            printReverse(inpString, length-1); //account for /n/r
        }
    } while (strcmp(inpString, "done\n") != 0 && strcmp(inpString, "d\n") != 0 && strcmp(inpString, "Done\n") != 0);

    //printReverse(String, strlen(String));

    return 0;
}

