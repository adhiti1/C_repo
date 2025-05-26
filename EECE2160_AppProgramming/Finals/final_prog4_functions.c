#include "final_prog4_functions.h"
#define _CRT_SECURE_NO_WARNINGS     // Necessary on Visual Studio
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//Get the number of integers from file name so we can use it during reading file.
int getNumIntFromInpFile(char inpFileName[]) {
	char* ptr;
	char* ptr1;
	char tempInt[100];

	ptr = strchr(inpFileName, '_');
	ptr1 = strtok(ptr, "vals");

	//remove the _
	for (int i = 1; i < strlen(ptr1); i++)
		tempInt[i - 1] = ptr1[i];
	//terminate the string
	tempInt[strlen(ptr1) - 1] = '\0';
	
	return atoi(tempInt);

}

//Function opens a file.  Parameter is file name and access. Returns file pointer
FILE* fileOpen(char fileName[], char mode[]) {
	FILE* fp;

	fp = fopen(fileName, mode);
	if (fp == NULL) {
		printf("Cannot open input file %s\n", fileName);
	}
	return fp;
}

//finds output file name based on first 2 paramenters. 
//if input file name commands1.txt then output file name is commands1_out.txt
void setFileName(char inpName[], char outName[]) {
	int j=0;
	int index;

	for (int i = 0; i < strlen(inpName); i++) {
		if (isdigit(inpName[i]) != 0) {
			index = i;
			break;
		}
	}
	for (int i = 0; i <= index; i++)
		outName[i] = inpName[i];
	outName[index + 1] = '\0';
	strcat(outName, "_out.txt");

}


//www.tutorialspoint.com/c-program-to-sort-an-array-in-an-ascending-order
//sorts array in ascending manner
void sortArray(int paramArray[], int paramLength) {
	int a;
	for (int i = 0; i < paramLength; ++i) {
		for (int j = i + 1; j < paramLength; ++j) {
			if (paramArray[i] > paramArray[j]) {
				a = paramArray[i];
				paramArray[i] = paramArray[j];
				paramArray[j] = a;
			}
		}
	}
}



//find median
double median(int paramArray[], int paramLength) {
	int remainder;
	double median;
	int i;

	sortArray(paramArray, paramLength);

	remainder = paramLength%2;
	if (remainder == 0)
		median = 1.0*(paramArray[(paramLength / 2)-1] + paramArray[(paramLength / 2) ]) / 2;
	else {
		i = round(paramLength / 2);
		median = paramArray[i];
	}
		
	return median;
}

//check if input values file name has specific format
//return is 0 for valid and 1 for invalid
int checkInpValFileName(char inpFileName[]) {
	char* token;
	int index = -1;
	char tempFile[1000];

	//check if it ends with vals.bin
	strcpy(tempFile, inpFileName);
	token = strstr(tempFile, "vals.bin");
	if (token == NULL) {
		printf("Invalid file name %s\n", inpFileName);
		return 1;
	}

	//check if there is an integer after _ to indicate number of values in the file

	for (int i = 0; i < strlen(inpFileName); i++) {
		if (isdigit(inpFileName[i]) != 0 && inpFileName[i-1] == '_' && i!=0) {
			index = i;
			break;
		}
	}
	if (index == -1) { //did not find an integer
		printf("Invalid file name %s\n", inpFileName);
		return 1;
	}

	return 0;

}

//check if input values command name has specific format
//return is 0 for valid and 1 for invalid
int checkInpCmdFileName(char inpFileName[]) {

	char* token;
	int index = -1;
	char tempFile[1000];

	//check if it ends with vals.bin
	strcpy(tempFile, inpFileName);
	token = strstr(tempFile, ".txt");
	if (token == NULL) {
		printf("Invalid file name %s\n", inpFileName);
		return 1;
	}

	//check if there is an integer after _ to indicate number of values in the file

	for (int i = 0; i < strlen(inpFileName); i++) {
		if (isdigit(inpFileName[i]) != 0 ) {
			index = i;
			break;
		}
	}
	if (index == -1) { //did not find an integer
		printf("Invalid file name %s\n", inpFileName);
		return 1;
	}

	return 0;

}


//check if user entered output file name is valid
//return is 0 for valid and 1 for invalid
int checkOutputFileName(char inpCmdFileName[], char inpOutFileName[]) {
	char genOutputFileName[1000];

	setFileName(inpCmdFileName, genOutputFileName);
	if (strcmp(genOutputFileName, inpOutFileName) != 0) {
		printf("Invalid Output file name %s", inpOutFileName);
		return 1;
	}
	return 0;

}



//function that takes command line and then returns command and number
//for example copy 50 passed as input will return 50 and 2nd parameter will have copy as value
int splitCommandLine(char inpCmdLine[], char cmd[]) {
	char* ptr;
	char tempInt[50];
	int val;

	if (strcmp(inpCmdLine, "exit") == 0) {
		strcpy(cmd, "exit");
		return 0;
	}
	//find the command
	switch (inpCmdLine[0]) {
	case 'c':
		strcpy(cmd, "copy");
		break;
	case 'r':
		strcpy(cmd, "reverse");
		break;
	case 's':
		strcpy(cmd, "sort");
		break;
	case 'm':
		strcpy(cmd, "median");
		break;
	default:
		strcpy(cmd, "exit");
	}

	//find the values in the command
	ptr = strchr(inpCmdLine, ' ');

	//remove the _
	for (int i = 1; i < strlen(ptr); i++)
		tempInt[i - 1] = ptr[i];
	//terminate the string
	tempInt[strlen(ptr) - 1] = '\0';

	val = atoi(tempInt);

	return val;

}

