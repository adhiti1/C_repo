// Final_Program_116.cpp 
// Adhiti Venkatesh

#define _CRT_SECURE_NO_WARNINGS     // Necessary on Visual Studio
#include <iostream>
#include <stdio.h>
#include "final_prog1_functions.h"
#include "final_prog1_functions.c"


int main()
{

    char inpStr1[2000];
    char inpStr2[2000];

    do {
        printf("Enter two strings: ");
        scanf("%s %s", inpStr1, inpStr2);
        
        if (strcmp(inpStr1, inpStr2) == 0) {
            printf("Entered %s twice; now exiting ...\n", inpStr1);
            break;
        }
  
        //check for palindrome
        if (isPalindrome(inpStr1) == 0)
            printf("%s is a palindrome\n", inpStr1);
        else
            printf("%s is not a palindrome\n", inpStr1);
        
        if (isPalindrome(inpStr2) == 0)
            printf("%s is a palindrome\n", inpStr2);
        else
            printf("%s is not a palindrome\n", inpStr2);


        //check if it is a substring of another
        // strstr(str1, str2)
        //strstr function in string.h returns pointer to first occurence of str2 in str1 or null if not found


        if (strstr(inpStr2, inpStr1) == NULL)
            printf("%s is not a substring of %s\n", inpStr1, inpStr2);
        else
            printf("%s is a substring of %s\n", inpStr1, inpStr2);

        if (strstr(inpStr1, inpStr2) == NULL)
            printf("%s is not a substring of %s\n", inpStr2, inpStr1);
        else
            printf("%s is a substring of %s\n", inpStr2, inpStr1);

        //most common letter

        printf("Most common letter in %s is %c\n", inpStr1, getCommonLetter(inpStr1));
        printf("Most common letter in %s is %c\n", inpStr2, getCommonLetter(inpStr2));

    
    } while (strcmp(inpStr1, inpStr2) != 0);

    return 0;
}
