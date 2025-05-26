
// Lines used for conditional compilation--ensures header isn't included multiple times
#ifndef prog5721_functions_h
#define prog5721_functions_h

//printArr prints array
void printArr(int paramArray[], int paramLength, char category[]);

//fillArr fills array for the category by displaying appropriate prompt
void fillArr(int paramArray[], int paramLength, char prompt[], char category[]);

//clears buffer
void clear(void);

//calculates average of values in array
double arrayAvg(int paramArray[], int paramLength);

//sorts array in ascending manner
void sortArray(int paramArray[], int paramLength);

//getGrade stores the grade based on a score in an array
void getGrade(char paramArray[], double score);

//get max value in an array
int getMaxInArray(int paramArray[], int paramLength);

#endif /* More conditional compilation--end of prog5_functions_h */