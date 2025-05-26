//
//  Employee.c
//
//  Source file for Employee type for Summer 2020 Final Exam
//

// YOU MUST COMPLETE THE FUNCTIONS IN THIS FILE WITH YOUR OWN CODE

#include "Employee.h"
#include <stdio.h>
#include <string.h>

// Print information about employee
// Output format should be as follows:
//   Name (first middle last)
//   ID #xxxxxxxx (replace x's with actual 8-digit ID number)
//   If salaried: Salary: y per year (replace y with actual salary)
//   If hourly:   Wage: z per year (replace z with actual wage)
void printEmployee(Employee *e) {
	printName(&e->emplName);  // this prints employee name
	printf("ID %8d\n",e->ID);
	if (e->salaried == 1) {
		printf("Salary: %d per year", e->wage);
	}
	else {
		printf("Wage: %d per hour", e->wage);
	}
}

// Reads employee information into existing structure
// Function should prompt user to enter each piece of information:
//   Name
//   ID
//   Ask if employee is salaried (Y/N)
//      If answer's yes, prompt for salary
//      If answer's no, prompt for hourly wage
void readEmployee(Employee *e) {
	char Sal,ch;
	readName(&e->emplName);
	printf("Enter ID: ");
	scanf("%d",&e->ID);
	printf("\nIs employee salaried? (Y/N) ");
	scanf("%c%c",&Sal,&ch);
	if (Sal=='Y' || Sal =='y') {
		e->salaried = 1;
		printf("What is the employee's salary? ");
		scanf("%lf", &e->wage);
	}
	else { 
		e->salaried = 0;
		printf("What is the employee's wage? ");
		scanf("%lf", &e->wage);
	}

}

// Print list of employees, one at a time
void printList(Employee list[], int n) {
	for (int i = 0; i < n; i++) {
		printName(&list[i].emplName);
		printf("\n");
	}
}

// Select only salaried or hourly employees to print
// If argument sal == 1, print salaried employees
// If argument sal == 0, print hourly employees
void printSalHrly(Employee list[], int n, unsigned int sal) {
	for (int i = 0; i < n; i++) {
		if (sal == 1 && list[i].salaried==1) {
			printName(&list[i].emplName);
		}
		if (sal == 0 && list[i].salaried == 0) {
			printName(&list[i].emplName);
		}
	}
}

// Find employee in list, based on last name
// Returns index if employee with matching last name found, -1 otherwise
int findByLName(Employee list[], int n, char lname[]) {
	for (int i = 0; i < n; i++) {
		if (strcmp(list[i].emplName.last, lname)==0) {
			return i;
		}
	}
	return -1;		
}

// Find employee in list, based on ID #
// Returns index if employee with matching ID found, -1 otherwise
int findByID(Employee list[], int n, unsigned int eID) {
	for (int i = 0; i < n; i++) {
		if (list[i].ID = eID) {
			return i;
		}
	}
	return -1;
}
