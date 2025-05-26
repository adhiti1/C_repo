#ifndef final_prog2_functions_h
#define final_prog2_functions_h
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS     // Necessary on Visual Studio

//converts inteter to character for printing
char intToCharPlayer(int player);

//print gameboard

void printGameBoard(int gameBoard[6][7]);


//check if the player has 4 consecutive tokens for that row that he played recently
int horizontalWin(int gameBoard[6][7], int player, int rowPlayed);

//check if the player has 4 consecutive tokens for the  col that he played recently
int verticalWin(int gameBoard[6][7], int player, int colPlayed);

//check if the player has 4 consecutive tokens for the diagonal row that he played recently
int diagonalWin(int gameBoard[6][7], int player, int rowPlayed, int colPlayed);

//this function checks if the player has won from recent move.
//calls horizontal win, vertical win and diagonal win functions.
//if player wins in one of them then it does not call the remaining
int didPlayerWin(int gameBoard[6][7], int player, int rowPlayed, int colPlayed);


#endif
