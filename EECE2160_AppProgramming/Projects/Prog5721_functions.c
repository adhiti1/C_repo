
//flushes input
//stackoverflow.com/questions/7898215/how-can-i-clear-an-input-buffer-in-c
void clear(void)
{
	while (getchar() != '\n');
}

//fillArr fills array for the category by displaying appropriate prompt
void fillArr(int paramArray[], int paramLength, char prompt[], char category[]) {
	int counter;
	printf("%s", prompt);
	for (int i = 0; i < paramLength; i++) {
		counter = i + 1;
		printf("Enter %s %d:", category, counter);
		scanf("%d", &paramArray[i]);
	}
}

//printArr prints array
void printArr(int paramArray[], int paramLength, char category[]) {
	int counter = 0;
	int total = 0;
	for (int i = 0; i < paramLength; i++) {
		counter = i + 1;
		printf("%s %d: %d\n", category, counter, paramArray[i]);
		total += paramArray[i];
	}
	printf("AVERAGE: %0.2lf\n", total * 1.0 / counter);
}

//calculates average of values in array
double arrayAvg(int paramArray[], int paramLength) {
	int counter = 0;
	int total = 0;
	for (int i = 0; i < paramLength; i++) {
		counter = i + 1;
		total += paramArray[i];
	}
	return (total * 1.0 / counter);
}

//www.tutorialspoint.com/c-program-to-sort-an-array-in-an-ascending-order
//sorts array in ascending manner
void sortArray(int paramArray[], int paramLength) {
	int a;
	for (int i = 0; i < paramLength; ++i) {
		for (int j = i + 1; j < paramLength; ++j) {
			if (paramArray[i] > paramArray[j]) {
				a = paramArray[i];
				paramArray[i] = paramArray[j];
				paramArray[j] = a;
			}
		}
	}
}

//getGrade stores the grade based on a score in an array
void getGrade(char paramArray[], double score) {

	if (score >= 93.0)
		strcpy(paramArray, "A+");
	else if (score >= 90 && score < 93)
		strcpy(paramArray, "A-");
	else if (score >= 88 && score < 90)
		strcpy(paramArray, "B+");
	else if (score >= 83 && score < 88)
		strcpy(paramArray, "B");
	else if (score >= 80 && score < 83)
		strcpy(paramArray, "B-");
	else if (score >= 78 && score < 80)
		strcpy(paramArray, "C+");
	else if (score >= 73 && score < 78)
		strcpy(paramArray, "C");
	else if (score >= 70 && score < 73)
		strcpy(paramArray, "C-");
	else if (score >= 68 && score < 70)
		strcpy(paramArray, "D+");
	else if (score >= 60 && score < 68)
		strcpy(paramArray, "D");
	else
		strcpy(paramArray, "F");
}

//get max value in an array
int getMaxInArray(int paramArray[], int paramLength) {
	int maxValue = paramArray[0];
	for (int i = 0; i <= paramLength; i++) 
		if (paramArray[i] > maxValue) maxValue = paramArray[i];
	
	return maxValue;

}