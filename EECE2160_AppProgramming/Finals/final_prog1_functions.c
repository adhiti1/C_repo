#include "final_prog1_functions.h"
#define _CRT_SECURE_NO_WARNINGS     // Necessary on Visual Studio
#include <stdio.h>
#include <string.h>


int isPalindrome(char str1[]) {

	char reverseString[1000];
	int j;
	int length;

	
	length = strlen(str1);
	
	// To reverse string start from end and go back.
	//End of string has \0 as terminator.
	// start from length -1
	j = 0;
	
	for (int i = length-1; i >= 0; i--) {
		reverseString[j] = str1[i];
		j++;
	}
	//add string terminator
	reverseString[length] = '\0';


	//strrev is function in string.h that reverses a string
	if (strcmp(str1, reverseString) == 0)
		return 0; //is a palindrome
	else
		return 1; // is not a palindrome

}


int getIndexOfMaxValueInArray(int freq[], int length) {
	int index;
	int maxValue;

	maxValue = freq[0];
	for (int i = 0; i < length; i++) {
		if (maxValue < freq[i]) maxValue = freq[i];
	}
	

	for (int i = 0; i < length; i++) {
		if (freq[i] == maxValue) {
			index = i;
			break;
		}
	}


	return index;
}


//function will get the most common letter in the input string
//if there are more than 1 letter then it returns the one that comes first in alphabet.

char getCommonLetter(char str1[]) {

	int frequency[26]; // stores frequency of occurrences of alphabets in the string
	int index;
	char commonLetter;
	//set frequency array to zero

	for (int i = 0; i < 26; i++) frequency[i] = 0;

	//str[i] will have the character
	//subtracting from 'a' will get index of array. so, character 'a' will be index 0.
	for (int i = 0; i < strlen(str1); i++) {
		frequency[str1[i] - 'a'] = frequency[str1[i] - 'a'] + 1;
	}

	index = getIndexOfMaxValueInArray(frequency,26);
	commonLetter = index + 'a';
	return commonLetter;
}

