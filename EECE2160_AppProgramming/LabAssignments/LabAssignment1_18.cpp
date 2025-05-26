// LabAssignment1_18.cpp 
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied into zybooks


#include <stdio.h>

int main()
{
	int userNum;
	int userNum2;

	printf("Enter integer:\n");
	//visual studio requires scanf_s instead of scanf. using scanf gives an error.
	scanf_s("%d", &userNum); //get input. 
	
	printf("You entered: %d\n", userNum);
	printf("%d squared is %d\n", userNum, userNum * userNum);
	printf("And %d cubed is %d!!\n", userNum, userNum * userNum * userNum);

	printf("Enter another integer:\n");
	scanf_s("%d", &userNum2); //get input. 

	printf("%d + %d is %d\n", userNum, userNum2, userNum + userNum2);
	printf("%d * %d is %d\n", userNum, userNum2, userNum * userNum2);

	return 0;
}
