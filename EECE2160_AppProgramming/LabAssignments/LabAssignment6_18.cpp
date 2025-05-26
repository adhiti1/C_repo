// LabAssignment6_18.cpp 
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program outputs number in reverse. It uses arrays

#include <iostream>
#include <stdio.h>


int main()
{
	int numElements;
	int userVals[20];
	int inpLowerRange, inpUpperRange;
	char ch;

	//get number of elements
	scanf("%d ", &numElements);


	//get integers
	for (int i = 0; i <= numElements - 1; i++) {
		scanf("%d%c", &userVals[i], &ch);
	}

	//get range
	scanf("%d %d", &inpLowerRange, &inpUpperRange);


	for (int i = 0; i <= numElements - 1; i++) {
		//if the input is within range then print
		if (userVals[i] >= inpLowerRange && userVals[i] <= inpUpperRange)
			printf("%d,", userVals[i]);
	}
	printf("\n");
}
