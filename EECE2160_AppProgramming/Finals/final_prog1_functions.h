#ifndef final_prog1_functions_h
#define final_prog1_functions_h
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS     // Necessary on Visual Studio


//function returns a 0 if input string is a palindrome
int isPalindrome(char str1[]);


int getIndexOfMaxValueInArray(int freq[], int length);

//function will get the most common letter in the input string
//if there are more than 1 letter then it returns the one that comes first in alphabet.
char getCommonLetter(char str1[]);


#endif