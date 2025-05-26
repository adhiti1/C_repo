// LabAssignment9.71.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

int main()
{
	FILE* fp;

	char inName[20];
	char outName[20];
	int sum=0, product=1, count=0, inpNum;
	
	//Create other variables as needed

	printf("Enter file name: ");
	scanf("%s", inName);


	//Open the file
	fp = fopen(inName, "r");
	if (fp == NULL) {
		printf("Error: could not open %s!", inName);
		return 0;
	}



	printf("Values in input: ");
	// Add a loop below that reads one integer at a time from the file, stopping when it reaches the end of the file
	// It should also update variables and print back the number that was read
	
	
	while (fscanf(fp, "%d", &inpNum) != EOF) {
		printf("%d ", inpNum);
		count = count + 1;
		sum = sum + inpNum;
		product = product * inpNum;
	}
	


   //Close the input file
	fclose(fp);

	//printf("\nRead %d value(s) from file", );
	printf("\nRead %d value(s) from file\n", count);
   //Open the output file
	fp = fopen("output.txt", "w");
	if (fp == NULL) {
		printf("Error: could not open output.txt");
		return 0;
	}
   //Print out the sum, product, and average to the file
	fprintf(fp, "Sum: %d\n", sum);
	fprintf(fp, "Product: %d\n", product);
	fprintf(fp, "Average: %0.2lf\n", (sum*1.0)/count);
   //Close the output file
	fclose(fp);

	return 0;


}
