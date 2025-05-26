// Prog5.c
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program is a text based bank adventure.

#include "prog5_functions.h"
#include <iostream>
#include <stdio.h>
#include "prog5_functions.c"


int main()
{
    double bankBalance = 0;
    double newAmount = 0;
    int year = 0; //year is counter
    int newyear; 
    double rate = 0; //rate needs to be divided by 100. cannot be 5% needs to be 0.05
    char inpCmd, ch;

    do
    {
        printf("Year %d:\n", year);
        printf("There is $%0.2lf in your bank account with an annual rate of %0.3lf\n", bankBalance, rate);
        printf("What do you wish to do? (Wait, Invest, Quit): ");
        scanf("%c", &inpCmd);

        switch (toupper(inpCmd))
        {
        case 'W': //wait
            do //check to see if number of years is positive
            {
                printf("How many years do you want to wait? ");
                scanf("%d%c", &newyear, &ch); //getting carriage return as char so it doesn't mess up input command.
                if (newyear <= 0)
                    printf("Need a positive amount!\n");
            } while (newyear <= 0);
            printf("Waiting %d year(s)...\n", newyear);
            bankBalance = GetNewAmount(bankBalance, rate, newyear); //use current rate to get new balance for the years we are waiting.
            year = year + newyear; //add it to year counter.
            printf("\n");
            break;
        case 'I': //invest
            newAmount = GetPiggyBankMoney();  //find amount to invest
            printf("You got %0.2lf from your piggy bank and added it to your account!\n", newAmount);
            printf("Your total is now %0.2lf\n", bankBalance + newAmount);
            do //get positive interest rate
            {
                printf("What is new yearly rate? ");
                scanf("%lf%c", &rate, &ch); //error check; getting carriage return so it doesn't mess up input command
                if (rate <= 0)
                    printf("Neeed a positive amount!\n");
            } while (rate <= 0);

            year = year + 1; //default waiting period is 1 year
            bankBalance = GetNewAmount(bankBalance + newAmount, rate, 1); //find the new balance with interest.
            printf("\n");
            break;
        case 'Q':
            printf("bye!\n");
            break;
        default:
            printf("Invalid command %c!\n", inpCmd);
            while (scanf("%c", &ch) == 1 && ch != '\n') { ; }//loop through to clear buffer
            printf("\n");
            break;
        }

    } while (toupper(inpCmd) != 'Q');

    return 0;

}
