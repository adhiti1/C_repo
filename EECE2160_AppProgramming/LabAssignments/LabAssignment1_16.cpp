// LabAssignment1_16.cpp 
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied into zybooks


#include <stdio.h>

int main()
{
	int baseInt;
	int headInt;

//	printf("Enter base and Head Integer:\n");
	//visual studio requires scanf_s instead of scanf. using scanf gives an error.
	scanf_s("%d%d", &baseInt, &headInt); //get input. 
//	printf("Arrow output is shown below\n\n");

	printf("%5d\n", headInt); //pad to length of 5 with leading spaces
	printf("%5d%d\n", headInt,headInt);
	printf("%d%d%d%d%d%d%d\n", baseInt, baseInt, baseInt, baseInt, headInt, headInt, headInt);
	printf("%d%d%d%d%d%d%d%d\n", baseInt, baseInt, baseInt, baseInt, headInt, headInt, headInt,headInt);
	printf("%d%d%d%d%d%d%d\n", baseInt, baseInt, baseInt, baseInt, headInt, headInt, headInt);
	printf("%5d%d\n", headInt, headInt);
	printf("%5d\n", headInt);

	return 0;
}
