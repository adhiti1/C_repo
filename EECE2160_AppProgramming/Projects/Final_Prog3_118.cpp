// EECE.2160: ECE Application Programming
// Dr. Michael Geiger
// Summer 2020
// Exam 2
// Structures programming

// DO NOT MODIFY THIS FILE

#include <stdio.h>
#include "Employee.h"		// Implicitly includes Name.h
#include "Employee.c"
#include "Name.h"
#include "Name.c"

int main() {
	char cmd, cmd2;			// Single character commands
	Employee eList[10];		// List of students
	int nE = 0;				// Number of students in list
	unsigned int searchID;	// ID to find student by
	char searchLN[50];		// Last name to find student by
	int index;				// Index of found student

	// Loop until user enters 'Q'
	while (1) {
		printf("\nEnter command <A | P | F | Q>: ");
		scanf(" %c", &cmd);

		switch (cmd) {

			// Add employee
		case 'A': case 'a':
			if (nE == 10)		// List is full
				printf("No room in employee list\n");
			else {
				printf("Enter employee information:\n");
				readEmployee(&eList[nE]);
				nE++;
			}
			break;

			// Print list
		case 'P': case 'p':
			if (nE == 0)		// List is empty
				printf("No employees in list\n");
			else {
				printf("Employees to print (A = all, S = salaried, H = hourly): ");
				scanf(" %c", &cmd2);
				if (cmd2 == 'A' || cmd2 == 'a')
					printList(eList, nE);
				else
					printSalHrly(eList, nE, (cmd2 == 'S' || cmd2 == 's') ? 1 : 0);
			}
			break;

			// Find employee
		case 'F': case 'f':
			printf("Enter I to find by ID, L to find by last name: ");
			scanf(" %c", &cmd2);

			switch (cmd2) {
			case 'I': case 'i':
				printf("Enter search ID: ");
				scanf("%u", &searchID);
				index = findByID(eList, nE, searchID);
				break;

			case 'L': case 'l':
				printf("Enter last name: ");
				scanf("%s", searchLN);
				index = findByLName(eList, nE, searchLN);
				break;

			default:
				printf("Invalid selection\n");
				do {
					scanf("%c", &cmd2);
				} while (cmd2 != '\n');
				index = -2;
			}

			// Check results of find function
			if (index == -1)
				printf("Employee not found\n");
			else if (index >= 0) {
				printf("Employee found\n");
				printEmployee(&eList[index]);
			}
			break;

			// Exit program
		case 'Q': case 'q':
			return 0;

		default:
			printf("Invalid command %c\n", cmd);
		}
	}

	return 0;
}