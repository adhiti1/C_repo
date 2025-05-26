// Midterm_11_8.cpp 
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program reads 4 integers and does variety of checks


#include <iostream>
#include <stdio.h>
int main()
{
    int scanResult;
    int inp1, inp2, inp3, inp4;
    int checkError = 0; //initial value is 0
    int scanError = 0;
    char ch;

    printf("Inputs must increase from lowest to highest value, with first two values being odd and last two values being even\n");

    do {
        checkError = 0; //set to 0 at start of loop
        scanError = 0; //set to 0 at start of loop
        inp1 = NULL;
        inp2 = NULL;
        inp3 = NULL;
        inp4 = NULL;

        printf("Enter inputs:");


        scanResult = scanf("%d %d %d %d", &inp1, &inp2, &inp3, &inp4);
        if (scanResult != 4) { // did not read all 4 integers
            scanError = 1;
            //  printf("Error reading inputs\n");
            //  printf("%d %d %d %d", inp1, inp2, inp3, inp4);
              //scanf stops after first incorrect data type. 
              //setting input variables to null. so check for first 0.
            if (inp1 == 0)
                printf("Formatting error on input #1");
            else if (inp2 == 0)
                printf("Formatting error on input #2");
            else if (inp3 == 0)
                printf("Formatting error on input #3");
            else if (inp4 == 0)
                printf("Formatting error on input #4");
            checkError = 1;
            //clear buffer
            while (scanf("%c", &ch) == 1 && ch != '\n') { ; }//loop through to clear buffer
        }

        if (scanError != 1) { //if scan error then dont do any other check.
            //checking for odd
            if (inp1 % 2 == 0) {
                checkError = 1;
                printf("First input(%d) should be odd\n", inp1);
            }
            if (inp2 % 2 == 0) {
                checkError = 1;
                printf("Second input(%d) should be odd\n", inp2);
            }

            //checking for even
            if (inp3 % 2 != 0) {
                checkError = 1;
                printf("Third input(%d) should be even\n", inp3);
            }
            if (inp4 % 2 != 0) {
                checkError = 1;
                printf("Fourth input(%d) should be even\n", inp4);
            }

            //inputs should increase from lowest to highest
            if (inp1 > inp2 || inp1 > inp3 || inp1 >> inp4) {
                checkError = 1;
                printf("Inputs are out of order\n");
            }
            else if (inp2 > inp3 || inp2 > inp4) {
                checkError = 1;
                printf("Inputs are out of order\n");
            }
            else if (inp3 > inp4) {
                checkError = 1;
                printf("Inputs are out of order\n");
            }
        }
    } while (checkError == 1);

    printf("Inputs (%d %d %d %d) satisfy rules\n", inp1, inp2, inp3, inp4);
    return 0;
}
