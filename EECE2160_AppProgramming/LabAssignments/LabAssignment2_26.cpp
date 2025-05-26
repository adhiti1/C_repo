// LabAssignment2_26.cpp 
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied into zybooks


#include <stdio.h>

int main()
{
	int age, weight, heartrate, workoutTime;
	double calories;

	printf("Enter Age, weight, Heart Rate, WorkoutTime:\n");
	//visual studio requires scanf_s instead of scanf. using scanf gives an error.
	scanf_s("%d %d %d %d", &age, &weight, &heartrate,&workoutTime); //get input. 

	calories = ((age * 0.2757 + weight * 0.03295 + heartrate * 1.0781 - 75.4991) * workoutTime) / 8.368;

	printf("Calories: %0.2lf calories" "\n", calories);

	return 0;
}
