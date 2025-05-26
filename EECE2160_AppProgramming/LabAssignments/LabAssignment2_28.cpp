// LabAssignment2_28.cpp 
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied into zybooks


#include <stdio.h>

int main()
{
	double carMileage, costOfGas, gallonsUsed;
	

	printf("Enter car gas mileage and cost of gas:\n");
	//visual studio requires scanf_s instead of scanf. using scanf gives an error.
	scanf_s("%lf %lf", &carMileage, &costOfGas); //get input. 
	//prints cost of trip for 20, 75 and 500 miles
	printf("%0.2lf %0.2lf %0.2lf\n", (20 / carMileage) * costOfGas, (75 / carMileage) * costOfGas, (500 / carMileage) * costOfGas);

	
	return 0;
}
