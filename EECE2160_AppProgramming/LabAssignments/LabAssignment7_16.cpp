// LabAssignment7_16.cpp 
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program removes all non-alphabetic characters


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{

	char inpString[2000];
	char outString[2000] = "";
	int j = 0;

	scanf("%[^\n]s", &inpString);

	for (int i = 0; i <= strlen(inpString); i++) {
		if (isalpha(inpString[i]) != 0) {
			outString[j] = inpString[i];
			j++;
		}
	}
	printf("%s\n", outString);
	return 0;
}

