//
//  Employee.h
//
//  Header for Employee type for Summer 2020 Final Exam
//

// DO NOT MODIFY THIS FILE

#ifndef Employee_h
#define Employee_h

#include "Name.h"	// Allows use of Name structure, functions

// Employee structure definition
typedef struct {
	Name emplName;			// Employee name
	unsigned int ID;		// ID number
	unsigned int salaried;	// == 1 if salaried, == 0 if hourly
	double wage;			// Yearly salary if salaried; hourly wage if hourly
} Employee;

// Print information about employee
void printEmployee(Employee *e);

// Reads employee information into existing structure
void readEmployee(Employee *e);

// Print list of employees
void printList(Employee list[], int n);

// Select only salaried or hourly employees to print
void printSalHrly(Employee list[], int n, unsigned int sal);

// Find employee in list, based on last name
// Returns index if employee found, -1 otherwise
int findByLName(Employee list[], int n, char lname[]);

// Find employee in list, based on ID #
// Returns index if employee found, -1 otherwise
int findByID(Employee list[], int n, unsigned int eID);

#endif /* SINew_h */