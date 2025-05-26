// LabAssignment8_9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

typedef struct {
	char name[50];		// Student name
	int g1, g2, g3;	// Exam grades
} ScoreList;

//function to find minimum of 2 numbers
double minOfTwo(double num1, double num2) {
	if (num1 < num2) return num1; else return num2;
}

//function to find max of 2 numbers
double maxOfTwo(double num1, double num2) {
	if (num1 > num2) return num1; else return num2;
}

int main() {
	double average;
	double minAvg = 100;
	double maxAvg = 0;
	double stuMinAvg = 100;
	double stuMaxAvg = 0;
	char stuMinName[50];
	char stuMaxName[50];

	ScoreList myClass[8] =
	{
		{ "John Doe", 75, 85, 93 },
		{ "Jane Smith", 100, 83, 91 },
		{ "Tom Brady", 36, 38, 39 },
		{ "Fred Flintstone", 88, 77, 66 },
		{ "Meryl Streep", 79, 82, 11 },
		{ "Carl Lewis", 84, 88, 92 },
		{ "Grace Hopper", 71, 52, 85 },
		{ "Dennis Ritchie", 72, 78, 98 }
	};

	/*** ADD MORE VARIABLES HERE ***/

	// Visit all values in array, calculate average for each student, and print
	for (int i = 0; i <= 7; i++) {

		/*** CALCULATE AVERAGE ***/
		average = 1.0 * (myClass[i].g1 + myClass[i].g2 + myClass[i].g3) / 3;
		// Uncomment and fix print statement below
		// DO NOT CHANGE FORMAT SPECIFIERS: %-15s will print each student name
		//   with a field width of 15 chars and left justify it
		printf("Student: %-15s  Average: %.2lf\n", myClass[i].name, average);

		/*** DETERMINE MIN/MAX AVERAGES ***/
		minAvg = minOfTwo(minAvg, average);
		maxAvg = maxOfTwo(maxAvg, average);
		if (stuMinAvg > minAvg) {
			stuMinAvg = minAvg;
			strcpy(stuMinName, myClass[i].name);
		}
		if (stuMaxAvg < maxAvg) {
			stuMaxAvg = maxAvg;
			strcpy(stuMaxName, myClass[i].name);
		}

	}

	printf("----------------------------------------\n");
	/*** ADD PRINT STATEMENTS TO PRINT MIN/MAX AVERAGES ***/
//	printf("Min Average %.2lf\n", minAvg);
//	printf("Max Average %.2lf\n", maxAvg);
	printf("Minimum average: %s %.2lf\n", stuMinName, stuMinAvg);
	printf("Maximum average: %s %.2lf\n", stuMaxName, stuMaxAvg);
	return 0;
}