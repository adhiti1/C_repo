// Program5_7_21.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// The program accepts several string commands that allow user to read or modify the state of different 
// arrays storing test and assignment scores. The program can also use these scores to calculate a 
// weighted average to determine a letter grade using the same rubric for the course
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "prog5721_functions.h"
#include "prog5721_functions.c"

int main()
{
	//define constants
	const int NUM_TESTS = 3;
	const int NUM_PGMS = 7;
	const int NUM_LABS = 9;
	const int NUM_EXERCISES = 9;
	const int ATTENDANCE = 1;

	//weights for grade determination.  Attendance is left alone and is obtained from score.
	const double LAB_WEIGHT = 0.20;
	const double PROGRAM_WEIGHT = 0.30;
	const double EXERCISE_WEIGHT = 0.10;
	const double HIGHEST_EXAM_WEIGHT = 0.15;
	const double OTHER_2EXAM_WEIGHT = 0.10;

	//variables for finding grade
	double labAvg;
	double progAvg;
	double exerciseAvg;
	double finalAvg;
	char finalGrade[5];

	char inpCmd[25];
	char inpCategory[25];
	//char inpAverage[25];


	//array to store scores
	int testScore[NUM_TESTS];
	int programScore[NUM_PGMS];
	int labScore[NUM_LABS];
	int exerciseScore[NUM_EXERCISES];
	int attendanceScore;

	int maxTestScore;
	int k=1;
	int remaining2Tests = 0;

	//prompts
	const char helpPrompt[20480] = {
	"Commands:\nhelp:\t\tPrint this command list\nenter:\t\tenter values for one type of assignment\naverage:\tcalculate/print average for one type of assignment\ngrade:\t\tcalculate/print letter grade based on assignment scores\nexit:\t\t exit program\n"
	};
	const char enterPrompt[20480] = {
	"Category to enter (tests, programs, labs, exercises, attendance): "
	};
	const char averagePrompt[20480] = {
	"Enter category to average (programs, labs, exercises): "
	};
	const char exitPrompt[2048] = {
	"Exiting program ... "
	};

	//categories
	const char enter_category[5][1000] = { "tests","programs","labs","exercises","attendance" };
	const char average_category[3][1000] = { "programs","labs","exercises" };

	char tmpPrompt[2000];

	//Menu Prompt

	do {
		printf("Enter command (type help to see all commands): ");
		scanf("%20[^\n]%*c", inpCmd);

		if (strcmp(inpCmd, "help") == 0) {
			printf("%s", helpPrompt);
		}
		else if (strcmp(inpCmd, "enter") == 0) {

			do { //sub menu for enter

				printf("%s", enterPrompt);
				scanf("%20[^\n]%*c", inpCategory);
				if (strcmp(inpCategory, "tests") == 0) {
					strcpy(tmpPrompt, "Enter 3 test scores:\n");
					fillArr(testScore, NUM_TESTS, tmpPrompt, inpCategory);
					clear(); //clear buffer
				}
				else if (strcmp(inpCategory, "programs") == 0) {
					strcpy(tmpPrompt, "Enter 7 program scores:\n");
					fillArr(programScore, NUM_PGMS, tmpPrompt, inpCategory);
					clear();
				}
				else if (strcmp(inpCategory, "labs") == 0) {
					strcpy(tmpPrompt, "Enter 9 lab collection scores \n");
					fillArr(labScore, NUM_LABS, tmpPrompt, inpCategory);
					clear();
				}
				else if (strcmp(inpCategory, "exercises") == 0) {
					strcpy(tmpPrompt, "Enter 9 chapter exercise scores:\n");
					fillArr(exerciseScore, NUM_EXERCISES, tmpPrompt, inpCategory);
					clear();
				}
				else if (strcmp(inpCategory, "attendance") == 0) {
					printf("Enter attendance score (0-5): ");
					scanf("%d", &attendanceScore);
					clear();
				}
				else
					printf("Invalid Category %s\n", inpCategory);
				printf("\n");
				//			} while (attendanceDataEntered == 0 || exerciseDataEntered == 0 || labDataEntered == 0 || progDataEntered == 0 || testDataEntered == 0);//until all 5 categories are entered
			} while (strcmp(inpCategory, "attendance") != 0 && strcmp(inpCategory, "exercises") != 0 && strcmp(inpCategory, "labs") != 0 && strcmp(inpCategory, "programs") != 0 && strcmp(inpCategory, "tests") != 0);
		}
		else if (strcmp(inpCmd, "average") == 0) {
			do {
				printf("%s", averagePrompt); //sub menu
				scanf("%20[^\n]%*c", inpCategory);
				if (strcmp(inpCategory, "programs") == 0) {
					strcpy(tmpPrompt, "Program");
					printArr(programScore, NUM_PGMS, tmpPrompt);
				}
				else if (strcmp(inpCategory, "labs") == 0) {
					strcpy(tmpPrompt, "Lab");
					printArr(labScore, NUM_LABS, tmpPrompt);
				}
				else if (strcmp(inpCategory, "exercises") == 0) {
					strcpy(tmpPrompt, "Chapter exercise");
					printArr(exerciseScore, NUM_EXERCISES, tmpPrompt);

				}
				else
					printf("Invalid Category %s\n", inpCategory);
			} while (strcmp(inpCategory, "exercises") != 0 && strcmp(inpCategory, "labs") != 0 && strcmp(inpCategory, "programs") != 0);

		}
		else if (strcmp(inpCmd, "grade") == 0) {
			labAvg = arrayAvg(labScore, NUM_LABS);
			printf("Lab average (%d%%):\t\t%0.2lf\n", (int)(LAB_WEIGHT * 100), labAvg);
			progAvg = arrayAvg(programScore, NUM_PGMS);
			printf("Program average (%d%%)\t\t%0.2lf\n", (int)(PROGRAM_WEIGHT * 100), progAvg);
			exerciseAvg = arrayAvg(exerciseScore, NUM_EXERCISES);
			printf("Ch. exercise average (%d%%):\t%0.2lf\n", (int)(EXERCISE_WEIGHT * 100), exerciseAvg);
			printf("Attendance score (5%%):\t\t%-2d\n", attendanceScore);

			//	sortArray(testScore, NUM_TESTS); //sort it in ascending fashion
			//	printf("Highest exam grade (%d%%):\t%d\n", (int)(HIGHEST_EXAM_WEIGHT * 100), testScore[2]);

				//get max test score
			maxTestScore = getMaxInArray(testScore, NUM_TESTS);
			printf("Highest exam grade (%d%%):\t%d\n", (int)(HIGHEST_EXAM_WEIGHT * 100), maxTestScore);

			//	printf("2nd exam grade (%d%%) :\t\t%d\n", (int)(OTHER_2EXAM_WEIGHT * 100), testScore[1]);
			//	printf("3rd exam grade (%d%%) :\t\t%d\n", (int)(OTHER_2EXAM_WEIGHT * 100), testScore[0]);

			//for remaining 2 tests ignore max test score.

			k = 2; //initialize to 2nd exam
			for (int i = 0; i < NUM_TESTS; i++) {
				if (testScore[i] != maxTestScore) { //not max test score; print
					if (k == 2) { //2nd exam 
						printf("2nd exam grade (%d%%) :\t\t%d\n", (int)(OTHER_2EXAM_WEIGHT * 100), testScore[i]);
						k++;
						remaining2Tests = remaining2Tests+ testScore[i];
					}
					else {
						printf("3rd exam grade (%d%%) :\t\t%d\n", (int)(OTHER_2EXAM_WEIGHT * 100), testScore[i]);
						remaining2Tests = remaining2Tests+  testScore[i];
					}
				}
			}

			//finalAvg = (labAvg * LAB_WEIGHT) + (progAvg * PROGRAM_WEIGHT) + (exerciseAvg * EXERCISE_WEIGHT) + attendanceScore + (testScore[2] * HIGHEST_EXAM_WEIGHT) + (testScore[1] * OTHER_2EXAM_WEIGHT) + (testScore[0] * OTHER_2EXAM_WEIGHT);

//change the formula since we are not using sorted array
			finalAvg = (labAvg * LAB_WEIGHT) + (progAvg * PROGRAM_WEIGHT) + (exerciseAvg * EXERCISE_WEIGHT) + attendanceScore + (maxTestScore * HIGHEST_EXAM_WEIGHT) + (remaining2Tests * OTHER_2EXAM_WEIGHT);

			printf("FINAL AVERAGE:\t\t\t%0.2lf\n", finalAvg);
			getGrade(finalGrade, finalAvg);
			printf("FINAL GRADE:\t\t\t%s\n", finalGrade);
		}
		else if (strcmp(inpCmd, "exit") == 0) {
			printf("%s", exitPrompt);
		}
		else {
			//clear();
			printf("Invalid command %s\n", inpCmd);
			//clear();
		}
	} while (strcmp(inpCmd, "exit") != 0);

	return 0;

}