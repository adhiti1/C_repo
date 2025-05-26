// Midterm_11_9.cpp
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program asks the user to enter size of a symmetrical diamond shape, prints the shape
// and then asks if they want to print another one.

#include <iostream>
#include <stdio.h>

int main()
{
    int size;
    char inpChar;
    char inpc, ch;
    int spaceCounter, starCounter;
    int topHalf;
    char space = ' ';
    char star = '*';


    do {
        printf("Enter diamond size (must be odd): ");
        do {
            scanf("%d", &size);
            if (size % 2 == 0) {
                printf("Diamond size must be odd!\n");
                printf("Enter diamond size (must be odd): ");
            }
        } while (size % 2 == 0);

        printf("\n");
        //printing diamond
        
        //top half of diamond
        topHalf = size / 2;
        //printf("%d\n", topHalf);
        spaceCounter = topHalf;

        for (int i = 0; i < topHalf; i++) { //rows
            //printf("%d", spaceCounter);
            //spaces are symmetrical around stars.
            for (int j = 0; j < spaceCounter; j++) { //need to fill spaces
                printf("%c", space);
            }
            starCounter = size - 2 * spaceCounter;
            //printf("%d", starCounter);
            for (int k = 0; k < starCounter; k++) { //need to fill star
                printf("%c", star);
            }

            //commenting this out as it was failing auto grader test.
            /*
            for (int j = 0; j < spaceCounter; j++) { //need to fill spaces
                printf("%c", space);
                }
            */
            
            printf("\n");
            spaceCounter = spaceCounter - 1; //remove 1 space
        }


        //all stars
        for (int i = 0; i < size; i++)
            printf("%c", star);
        printf("\n");
        //bottom half of diamond
        //reflection of top; start with one space on either end.
        spaceCounter = 1;

        for (int i = 0; i < topHalf; i++) { //rows
            //printf("%d", spaceCounter);
            for (int j = 0; j < spaceCounter; j++) { //need to fill spaces
                printf("%c", space);
            }
            starCounter = size - 2 * spaceCounter;
            //printf("%d", starCounter);
            for (int k = 0; k < starCounter; k++) { //need to fill star
                printf("%c", star);
            }
            //commenting this out as it was failing auto grader test
            /*
            for (int j = 0; j < spaceCounter; j++) { //need to fill spaces
                printf("%c", space);
            }
            */

            printf("\n");
            spaceCounter = spaceCounter + 1; //increase space as it goes down
        }
        printf("\n");
        while (scanf("%c", &ch) == 1 && ch != '\n') { ; }//loop through to clear buffer

        printf("Print another diamond? ");
        do {
            scanf("%c", &inpChar);
            if ((toupper(inpChar) != 'Y') && (toupper(inpChar) != 'N')) {
                printf("Invalid response %c\n", inpChar);
                //clear buffer
                while (scanf("%c", &ch) == 1 && ch != '\n') { ; }//loop through to clear buffer
                printf("Print another diamond? ");
            }
        } while (toupper(inpChar) != 'Y' && toupper(inpChar) != 'N');
    } while (toupper(inpChar) == 'Y');

    return 0;
}

