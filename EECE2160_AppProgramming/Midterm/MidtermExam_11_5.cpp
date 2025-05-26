// Midterm_11_5.cpp 
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program reads a set of input values and generates some statistics from data


#include <iostream>
#include <stdio.h>

int main()
{
    int inp_win, inp_loss, inp_run, inp_strikeout, inp_pitched;

    double era;
    double strikeouts;

    printf("Enter wins & losses:");
    scanf("%d %d", &inp_win, &inp_loss);
    printf("Enter runs allowed:");
    scanf("%d", &inp_run);
    printf("Enter strikeouts:");
    scanf("%d", &inp_strikeout);
    printf("Enter innings pitched:");
    scanf("%d", &inp_pitched);

    //ERA = (earned run/innings pitched) * game innings
    //game innings =9 in baseball

    //multiply by double 9.0 before dividing so that it divides as a double and not as an integer.
    era = (inp_run * 9.0 / inp_pitched);
    strikeouts = (inp_strikeout * 9.0 / inp_pitched);

    printf("Record: %d-%d (%0.1f%%)\n", inp_win, inp_loss, ((inp_win * 100.0) / (inp_win + inp_loss)));
    printf("ERA: %0.2f\n", era);
    printf("SO / 9: %0.2f\n", strikeouts);

    return 0;
}
