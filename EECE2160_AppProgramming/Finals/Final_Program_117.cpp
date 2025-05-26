// Final_Program_117.cpp 
// Adhiti Venkatesh


#define _CRT_SECURE_NO_WARNINGS     // Necessary on Visual Studio
#include <iostream>
#include <stdio.h>
#include "final_prog2_functions.h"
#include "final_prog2_functions.c"

int main()
{
    int gameBoard[6][7]; //valid values are 1,2. 1 is r and 2 is y
    int availIndex[7]; //available index to insert token.  Default value is 5 (end of board)
    int currentPlayer; //1 is red; 2 is yellow

    int win;
    int inpColumn;
    
    int rowPlayed;
    int errorInput;

    /*  debugging
    int gameBoard[6][7] = {
        { 1,0,1,2,1,1,2},
        { 1,2,1,2,1,2,2},
        { 1,1,1,1,1,2,2},
        { 1,2,1,1,1,2,2},
        { 1,2,1,1,1,1,2},
        { 1,2,1,2,1,2,2}
    };
    

    currentPlayer = 1;
    win = didPlayerWin( gameBoard,currentPlayer, 0, 5);
    printf("%d\n\n", win);
    printGameBoard(gameBoard);
    */

    //set default to 5. As number of rows is 6. value of -1 means that column is full.
    for (int i = 0; i < 7; i++) availIndex[i] = 5;

    //clear gameboard
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 7; j++)
            gameBoard[i][j] = 0;
    
    //default player is red player
    currentPlayer = 1;

    printf("Welcome to Connect Four!\n");

    do {
        errorInput = 0;

        do {
            if (currentPlayer == 1)
                printf("Red turn--enter column (1-7): ");
            else
                printf("Yellow turn--enter column (1-7): ");
            scanf("%d", &inpColumn);
       
            if (inpColumn < 1 || inpColumn > 7) {
                printf("Error: column must be between 1 and 7\n");
                errorInput = 1;
                continue;
            }
           // printf("%d\n", availIndex[inpColumn-1]);
            if (availIndex[inpColumn-1] < 0) {
                printf("Error: Column %d is full\n", inpColumn);
                errorInput = 1;
                continue;
            }
            
            
            break;
        } while (1); //continue and break prevents infinite loop
                   


        //put in check for inpcolumn
        // have a do while loop
        inpColumn = inpColumn - 1;
        rowPlayed = availIndex[inpColumn];
        gameBoard[rowPlayed][inpColumn] = currentPlayer;
        availIndex[inpColumn] = availIndex[inpColumn] - 1;
        
        printGameBoard(gameBoard);

        if (didPlayerWin(gameBoard,currentPlayer,rowPlayed,inpColumn) == 0) {
            if (currentPlayer == 1) {
                printf("Red Player wins!\n");
                break;
            }
            else {
                printf("Yellow Player wins!\n");
                break;

            }
        }
        if (currentPlayer == 1) currentPlayer = 2;
        else currentPlayer = 1;

        //    break;

    } while (1); // infinte loop break condition is inside the loop
}
