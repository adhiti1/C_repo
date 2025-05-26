// LabAssignment2_29.cpp 
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied into zybooks


#include <stdio.h>

int main()
{
	long long phoneNumber;

	int areaCode;
	int midPhoneNumber;
	int last4PhoneDigits;

	printf("Enter phone Number:\n");
	//visual studio requires scanf_s instead of scanf. using scanf gives an error.
	scanf_s("%lld", &phoneNumber); //get input. 
	//assumption - starts without 0 and is a 10 digit number

	areaCode = phoneNumber / 10000000; //quotient is stored in area code as area code is integer
	midPhoneNumber = (phoneNumber % 10000000) / 10000; //taking reminder from previous step and then find quotient
	last4PhoneDigits = (phoneNumber % 10000000) % 10000 ;//reminder from last step.
	//printf("Area Code is %d\n", areaCode);
	//printf("Mid phone number is %d\n", midPhoneNumber);
	//printf("Last 4 Digits is %d", last4PhoneDigits);
	printf("(%d) %d-%d" "\n", areaCode, midPhoneNumber, last4PhoneDigits);
	return 0;
}
