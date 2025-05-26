
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "prog5_functions.h"

//Prompt the user for the number of each type of coin from the piggy bank
//Perform input validation as necessary (must all be integers and >=0), then calculate and return the amount in dollars
double GetPiggyBankMoney()
{
	int inpQtr, inpDime, inpNickel, inpPenny;

	printf("Please enter the number of quarters, dimes, nickels, and pennies, separated by spaces: ");
	do //loop until all inputs are >=0
	{
		scanf("%d %d %d %d", &inpQtr, &inpDime, &inpNickel, &inpPenny);
		if (inpQtr < 0 || inpDime < 0 || inpNickel < 0 || inpPenny < 0) {
			printf("All values must be >=0!\n");
			printf("Please enter the number of quarters, dimes, nickels, and pennies, separated by spaces: ");
		}
	} while (inpQtr < 0 || inpDime < 0  || inpNickel < 0 || inpPenny < 0);

	return (inpQtr * 0.25 + inpDime * 0.10 + inpNickel * 0.05 + inpPenny * 0.01);
}

//Given the principal amount in the bank account and the yearly rate, calculate and return the new amount after the given number of years has passed
double GetNewAmount(double principal, double rate, int years)
{
	//new amount is P*(1+r)raised to years
	return (principal * pow((1.0 + rate), years));
}

//Print a generic error message about bad format, then clear all characters from input until a newline is found
void ClearLine()
{
	char ch;

	printf("Error..Bad format. \n");
	while (scanf("%c", &ch) == 1 && ch != '\n') { ; }//loop through to clear buffer

}