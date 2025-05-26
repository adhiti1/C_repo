// Midterm_11_7.cpp 
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program reads 2 ranges and checks if there is an overlap
// does error checking on inputs.

#include <iostream>
#include <stdio.h>

int main()
{
	double inpRange1Low, inpRange1High;
	double inpRange2Low, inpRange2High;
	int result;

	printf("Enter range 1:");
	result = scanf("%lf %lf", &inpRange1Low, &inpRange1High);
	if (result != 2) // returns number of variables read correctly. should be 2.
		printf("Formatting error with range 1\n");
	else if (inpRange1Low >= inpRange1High) //dont get range 2 if there is an error with range 1
		printf("%0.1f should be less than %0.1f", inpRange1Low, inpRange1High);
	else {
		printf("Enter range 2:");
		result = scanf("%lf %lf", &inpRange2Low, &inpRange2High);
		if (result != 2) // returns number of variables read correctly. should be 2.
			printf("Formatting error with range 2\n");
		else if (inpRange2Low >= inpRange2High) //if error in range 2 then error out.
			printf("%0.1f should be less than %0.1f", inpRange2Low, inpRange2High);
		else if ((inpRange1Low <= inpRange2High) && (inpRange1High >= inpRange2Low))
			printf("(%0.1f, %0.1f) overlaps with (%0.1f, %0.1f)", inpRange1Low, inpRange1High, inpRange2Low, inpRange2High);
		else if ((inpRange2Low <= inpRange1High) && (inpRange2High >= inpRange1Low))
			printf("(%0.1f, %0.1f) overlaps with (%0.1f, %0.1f)", inpRange1Low, inpRange1High, inpRange2Low, inpRange2High);
		else
			printf("(%0.1f, %0.1f) does not overlap with (%0.1f, %0.1f)", inpRange1Low, inpRange1High, inpRange2Low, inpRange2High);
	}

	return 0;
}

