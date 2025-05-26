// Program3_4_11.cpp 
// Adhiti Venkatesh
// This program was created and debugged in visual studio 2022 and copied to zybooks
// This program implements guessing game.

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>

int main()
{

	//initial input variables
	int inpSeed;
	int inpMinRange, inpMaxRange;
	int numGuess, numRounds;

	int win = 0, loss = 0; //player wins and losses for game

	int i, j;
	int randomGuess, guess;

	//Initial inputs
	do {
		printf("Enter seed for random number generator: ");
		scanf("%d", &inpSeed);
		printf("\n");
		if (inpSeed < 0)
			printf("ERROR: Seed value should be > 0\n");
	} while (inpSeed < 0);

	printf("Seed: %d\n", inpSeed);
	do {
		printf("Enter range endpoints: ");
		scanf("%d %d", &inpMinRange, &inpMaxRange);
		printf("\n");
		if (inpMaxRange - inpMinRange < 4)
			printf("ERROR: Max value should be at least 4 more than min value\n");
		if (inpMaxRange < 0)
			printf("ERROR: Max value should be positive\n");
		if (inpMinRange < 0)
			printf("ERROR: Min value should be positive\n");

	} while ((inpMinRange < 0) || (inpMaxRange < 0) || (inpMaxRange - inpMinRange < 4));

	printf("Range endpoints: %d %d\n", inpMinRange, inpMaxRange);

	do {
		printf("Enter number of guesses per round: ");
		scanf("%d", &numGuess);
		printf("\n");
		if (numGuess <= 1)
			printf("ERROR: Must allow at least 2 guesses\n");
	} while (numGuess <= 1);

	printf("Number of guesses: %d\n", numGuess);

	do {
		printf("Enter number of rounds for game: ");
		scanf("%d", &numRounds);
		printf("\n");
		if (numRounds <= 0)
			printf("ERROR: Must allow at least 1 round\n");
	} while (numRounds <= 0);

	printf("Number of rounds: %d\n", numRounds);

	//set the seed
	srand(inpSeed);
	//loop through all rounds
	for (i = 1; i <= numRounds; i++) {
		//divide random by number of bins (max - min +1) and then add to min so we get a number between min and max.
		randomGuess = (rand() % (inpMaxRange - inpMinRange + 1)) + inpMinRange;
		//printf("%d\n", randomGuess);
		printf("ROUND %d\n", i);

		for (j = 1; j <= numGuess; j++) {
			printf("Enter guess #%d:", j);
			scanf("%d", &guess);
			//printf("\n");
			if (guess < randomGuess)
				printf("\n%d is too low!\n", guess);
			else if (guess > randomGuess)
				printf("\n%d is too high!\n", guess);
			else {
				printf("\nCorrect guess!\n");
				win = win + 1;

				printf("Current wins: %d\n", win);
				printf("Current losses: %d\n", loss);

				break;
			}
			if (j == numGuess) { //end of guesses and will loop out. update loss and print round stats.
				loss = loss + 1;
				printf("No more guesses--the correct answer was %d\n", randomGuess);
				//round summary
				printf("Current wins: %d\n", win);
				printf("Current losses: %d\n", loss);
			}
		}
	}
	//final stats
	printf("\n\n");
	printf("FINAL STATS\n");
	printf("Wins: %d\n", win);
	printf("Losses: %d\n", loss);
	printf("Winning percentage: %0.2lf%%", (win * 100.0) / (win + loss));
	return 0;
}
