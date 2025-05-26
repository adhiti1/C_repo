#ifndef final_prog4_functions_h
#define final_prog4_functions_h
#include <stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS     // Necessary on Visual Studio

//Get the number of integers from file name so we can use it during reading file.
int getNumIntFromInpFile(char inpFileName[]);

//Function opens a file.  Parameter is file name and access. Returns file pointer
FILE* fileOpen(char fileName[], char mode[]);

//finds output file name based on first 2 paramenters. 
//if input file name commands1.txt then output file name is commands1_out.txt
void setFileName(char inpName[], char outName[]);

//check if input values file name has specific format
//return is 0 for valid and 1 for invalid
int checkInpValFileName(char inpFileName[]);

//check if input values command name has specific format
//return is 0 for valid and 1 for invalid
int checkInpCmdFileName(char inpFileName[]);

//check if user entered output file name is valid
//return is 0 for valid and 1 for invalid
int checkOutputFileName(char inpCmdFileName[], char inpOutFileName[]);


//sorts array in ascending manner
void sortArray(int paramArray[], int paramLength);

//find median
double median(int paramArray[], int paramLength);

//function that takes command line and then returns command and number
//for example copy 50 passed as input will return 50 and 2nd parameter will have copy as value
int splitCommandLine(char inpCmdLine[], char cmd[]);
#endif