#include "final_prog2_functions.h"
#define _CRT_SECURE_NO_WARNINGS     // Necessary on Visual Studio
#include <stdio.h>
#include <string.h>



//check if the player has 4 consecutive tokens for that row that he played recently
int horizontalWin(int gameBoard[6][7], int player, int rowPlayed) {
	int count = 0;

//	printf("player %d rowplayed- %d\n", player, rowPlayed);
	for (int i = 0; i < 7; i++) {
		if (gameBoard[rowPlayed][i]==player) {
			count = count + 1;
			if (count >= 4) break;
		}
		else count = 0;
	}
//	printf(" count %d\n", count);
	if (count>=4) return 0;
	else return 1;
}

//check if the player has 4 consecutive tokens for the  col that he played recently
int verticalWin(int gameBoard[6][7], int player, int colPlayed) {
	int count = 0;
	//printf("I am in vertical win %d %d\n", player, colPlayed);
	for (int i = 0; i < 5; i++) {
		if (gameBoard[i][colPlayed] == player) {
			count = count + 1;
			if (count >= 4) break;
		}
		else count = 1;
	}
	//printf("count %d\n", count);
	if (count >= 4) return 0;
	else return 1;
}

//check if the player has 4 consecutive tokens for the diagonal row that he played recently
int diagonalWin(int gameBoard[6][7], int player, int rowPlayed, int colPlayed) {
	int count;

	int i,j,whileCounter = 1;

	int leftToken[7]; // left diagonal
	int rightToken[7]; // right diagnoal

	//printf("%d %d\n", rowPlayed, colPlayed);

		// For the left diagnoal find the current position given by rowplayed and colplayed
		// subtract 1 from row and col until row <0 or col < 0
		// add 1 to row and col until row >5 or col >6
		// put values from gameboard into left token array
		// then check left token array for consecutive tokens for the player

		//i is row and j is col
		//adding +1 to row and col


	whileCounter = 1;
	j = colPlayed;
	i = rowPlayed;
	while (whileCounter <= 7) {
		leftToken[j] = gameBoard[i][j];
		i = i + 1;
		j = j + 1;
		if ((i > 5) || (j > 6)) break; //outside game board
		}

	//i is row and j is col
	//adding +1 to row and col


	whileCounter = 1;
	j = colPlayed;
	i = rowPlayed;
	while (whileCounter <= 7) {
		leftToken[j] = gameBoard[i][j];
		i = i - 1;
		j = j - 1;
		if ((i <0) || (j <0)) break; //outside game board
	}

// For the right diagnoal find the current position given by rowplayed and colplayed
// subtract 1 from row and  add 1 to col until row <0 or col > 6
// add 1 to row and subtract 1 from col until row >5  or col <0
// put values from gameboard into right token array
// then check right token array for consecutive tokens for the player

//i is row and j is col
//subtract 1 from row and add 1 to col
//check if row < 0 or col > 6

whileCounter = 1;
j = colPlayed;
i = rowPlayed;
while (whileCounter <= 7) {
	rightToken[j] = gameBoard[i][j];
	i = i - 1;
	j = j + 1;
	if ((i < 0) || (j > 6)) break; //outside game board
}

//i is row and j is col
//adding +1 to row and subtract 1 from col
// check if row >5 or col < 0

whileCounter = 1;
j = colPlayed;
i = rowPlayed;
while (whileCounter <= 7) {
	rightToken[j] = gameBoard[i][j];
	i = i + 1;
	j = j - 1;
	if ((i > 5) || (j < 0)) break; //outside game board
}

//print left token and right token
/*printf("left token\n");
for (int l = 0; l < 6; l++) printf("%d ", leftToken[l]);
printf("\n");

printf("right token\n");
for (int l = 0; l < 6; l++) printf("%d ", rightToken[l]);
printf("\n");
*/
// check if left token and right token have consecutive player values
count = 0;
for (int l = 0; l < 6; l++) {
	if (leftToken[l] == player) count++;
	else count = 0;
	if (count >= 4) break;
}

//printf("left token count= %d\n", count);
if (count >= 4) return 0; //has won


// check if right token and right token have consecutive player values
count = 0;
for (int l = 0; l < 6; l++) {
	if (rightToken[l] == player) count++;
	else count = 0;
	if (count >= 4) break;
}
//printf("right token count= %d\n", count);
if (count >= 4) return 0; //has won
else return 1;

}


//this function checks if the player has won from recent move.
//calls horizontal win, vertical win and diagonal win functions.
//if player wins in one of them then it does not call the remaining
int didPlayerWin(int gameBoard[6][7], int player, int rowPlayed, int colPlayed) {
	int win;

	win = horizontalWin(gameBoard, player, rowPlayed);

	if (win == 0) {
		//printf("horizontal win\n");
		return 0; // he has won with horizontal check; no need to check others
	}
	win = verticalWin(gameBoard, player, colPlayed);

	if (win == 0) {
		//printf("vertical win\n");
		return 0; // he has won with veritcal check; no need to check others
	}

	win = diagonalWin(gameBoard, player, rowPlayed, colPlayed);

	if (win == 0) {
		//printf("Diagonal win\n");
		return 0;
	}
	else
		return 1;

}

char intToCharPlayer( int player) {
	if (player == 1) return 'r';
	else if (player == 2) return 'y';
	else return ' ';
}

void printGameBoard(int gameBoard[6][7]) {

	printf(" 1 2 3 4 5 6 7\n");
	for (int i = 0; i < 6; i++) {
		printf("|");
		for (int j = 0; j < 7; j++) {
			if (j<6)
				printf("%c ", intToCharPlayer(gameBoard[i][j]));
			else
				printf("%c", intToCharPlayer(gameBoard[i][j]));
		}
		printf("|\n");
	}
	printf("+-------------+\n");
}


