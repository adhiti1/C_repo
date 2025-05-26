// LabAssignment2_27.cpp 
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied into zybooks


#include <stdio.h>

int main()
{
	double caffeineMg;
	int duration; // in hours

	printf("Enter Caffeine Amount:\n");
	//visual studio requires scanf_s instead of scanf. using scanf gives an error.
	scanf_s("%lf", &caffeineMg); //get input. 

	duration = 6;
	caffeineMg = caffeineMg / 2; //half life is 6 hours
	printf("After %d hours: %0.2lf mg\n",duration, caffeineMg );
	
	duration = 12;
	caffeineMg = caffeineMg / 2; //next 6 hours; strength is reduced by half
	printf("After %d hours: %0.2lf mg\n",duration, caffeineMg);
	
	duration = 18;
	caffeineMg = caffeineMg / 2; //strength reduced by half
	duration = 24;
	caffeineMg = caffeineMg / 2; //strength reduced by half

	printf("After %d hours: %0.2lf mg\n", duration, caffeineMg);

	return 0;
}
