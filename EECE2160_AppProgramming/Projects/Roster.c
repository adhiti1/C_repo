/*** REPLACE THIS COMMENT WITH YOUR OWN HEADER COMMENT ***/

#include "Roster.h"
#define _CRT_SECURE_NO_WARNINGS     // Necessary on Visual Studio
#include <stdio.h>

int findPosInRoster(Roster* r, Name* n) {
	int p;
	printf("inside findposinroster\n");
//	printf("%d", r->ns);
	for (int i = 0; i < r->ns; i++) {
//		printf("%d\n", i);
		//printNameLFM(&r->students[i]);
		if (lessThan(n,&r->students[i]) == 1) {
			p = i;
			break;
		}
		else
			p = i + 1;
//		printf("%d\n", p);
	}
	return p;
}

// Add student to roster; returns 1 if successful or 0 if roster full
int addStudent(Roster* r, Name* n) {
  //roster structure has the following variables
  // ns is the number of students
  // students[100] of type name.

// To add name in the student array we need to find the correct place to insert it.
// student array is sorted in ascending order.

	int pos;
//	printf("calling function\n");
	if (r->ns == 0) 
		pos = 0;
	else
		pos = findPosInRoster(r, n);

//	printf("%d\n", pos);

	if (r->ns +1 > r->cap) return 0; //cannot add any more than capacity

	//move array to right to free up space for addition of name

	if (r->ns != 0) { //not first entry
		for (int i = r->ns + 1; i >= pos; i--) {
//			printf("moving array\n");
//			printNameLFM(&r->students[i - 1]);
			r->students[i] = r->students[i - 1];
		}
	}
	r->students[pos] = *n;

	//increase number of students
	r->ns = r->ns + 1;
   
   return 1;   

}

// Print contents of roster
void printRoster(Roster* r) {
  
	printf("%s\n", r->course);
	printf("Instructor: ");
	printNameLFM(&r->instructor);
//	printName(&r->instructor);
	printf("Course meetings: %s %s in %s\n", r->days, r->time, r->room);
	printf("Enrollment cap: %d\n", r->cap);
	printf("Number enrolled: %d\n", r->ns);
	if(r->ns != 0) printf("Class roster:\n");
	for (int i = 0; i < r->ns; i++) {
		printNameLFM(&r->students[i]);
	}
}

// Find student in roster; returns 1 if successful or 0 if student not found
int findStudent(Roster* r, Name* n) {
	int found = 0;
   
	for (int i = 0; i < r->ns; i++) {
		if (equal(&r->students[i], n)) {
			found = 1;
				break;
		}
	}
	if (found == 1) return 1;
	else return 0;
  }

   
