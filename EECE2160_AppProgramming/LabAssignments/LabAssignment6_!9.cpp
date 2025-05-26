// LabAssignment6_19.cpp 
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program reads list of integers and outputs two smallest integer in ascending order

#include <iostream>
#include <stdio.h>

int minofTwo(int num1, int num2) {
	if (num1 < num2) return num1; else return num2;
}

int maxofTwo(int num1, int num2) {
	if (num1 > num2) return num1; else return num2;
}


int main()
{
	int numElements;
	int userVals[20];
	char ch;
	int smallest = 99999999; //assign big number
	int secondSmallest = 99999999; //assign big number
	int s1, s2, tempS, tempSS;

	//get number of elements
	scanf("%d ", &numElements);


	//get integers
	for (int i = 0; i <= numElements - 1; i++) {
		scanf("%d%c", &userVals[i], &ch);

		//First value scanned. Set smallest and second smallest to save value.
		if (i == 0) {
			smallest = userVals[i];
			secondSmallest = userVals[i];
			//printf("%d %d %d\n", smallest, secondSmallest, userVals[i]);
		}
		else if (i == 1) { //second value scanned. set it to correct value
			smallest = minofTwo(smallest, userVals[i]);
			secondSmallest = maxofTwo(secondSmallest, userVals[i]);
			//printf("%d %d %d\n", smallest, secondSmallest, userVals[i]);
		}
		else {
			//find the smallest between 3 numbers - smallest, second smallest and input number.
			s1 = minofTwo(smallest, userVals[i]);
			s2 = minofTwo(secondSmallest, userVals[i]);
			tempS = minofTwo(s1, s2);
			//exclude smallest from smallest, second smallest and uservals and then find smallest between remaining.
			if (tempS == smallest) tempSS = minofTwo(secondSmallest, userVals[i]);
			else if (tempS == secondSmallest) tempSS = minofTwo(smallest, userVals[i]);
			else
				tempSS = minofTwo(smallest, secondSmallest);
			//set smallest and second smallest from temp variables.
			smallest = tempS;
			secondSmallest = tempSS;
			//printf("%d %d %d\n", smallest, secondSmallest, userVals[i]);
		}
	}
	printf("%d %d", smallest, secondSmallest);

	return 0;
}
