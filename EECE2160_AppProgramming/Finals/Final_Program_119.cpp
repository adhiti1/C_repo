// Final_Program_119.cpp 
// Adhiti Venkatesh

#include <stdio.h>
#include <iostream>
#include "final_prog4_functions.h"
#include "final_prog4_functions.c"
#define _CRT_SECURE_NO_WARNINGS     // Necessary on Visual Studio
#define MAXLINE 15 //max characters in a line in commands file

int main()
{
    int inpFileValues;
    char inpValsFileName[100] = "testfile_abcvals.bin";
    char inpCmdFileName[100] = "commands1.txt";
    char outputFileName[100];

    char cmdLine[MAXLINE]; //each line in command file
    char* fgetsResult; // error
    char cmd[15]; //command
    int cmdVal; //number of val in command line

    int checkFile = 0;

    int tempReverse[20];  
    int tempSort[20];

    double medianVal;

    FILE* fpVals= NULL;
    FILE* fpCmd = NULL;
    FILE* fpOut = NULL;

    //access mode
    char binaryReadMode[5];
    char textWriteMode[5];
    char textReadMode[5];

    //count of values in the input file
    int inpValCount;
    int inpValArray[2000];
    int inpCount;

    int curValArrayIndex;
    /*
    int paraA[4] = { 1,2,3,4 };
    double m;
    int i;

    i = checkInpCmdFileName(commandFile);
   printf("%d\n", i);
   
    inpFileValues = getNumIntFromInpFile(inpFilename);
    //printf("%d\n", t);

    setFileName(commandFile, outFile);

        printf("%s\n", outFile);

        m = median(paraA, 4);
    
    */

    strcpy(binaryReadMode, "rb");
    textWriteMode[0] = 'w';
    textWriteMode[1] = '\0';
    textReadMode[0] = 'r';
    textReadMode[1] = '\0';

    checkFile = 0; //set it to 0 as a default
    //prompt for binary input file
    do {
        printf("Enter binary input file name: ");
        scanf("%s", &inpValsFileName);
        checkFile = checkInpValFileName(inpValsFileName);
        if (checkFile == 0) {
            fpVals = fileOpen(inpValsFileName, binaryReadMode);
            if (fpVals == NULL) { //file cannot be open
                checkFile = 1;
                printf("Invalid file name %s\n", inpValsFileName);
            }
        }
    } while (checkFile !=0);

    
    //prompt for command input file name
    checkFile = 0; //set it to 0 as a default
        do {
            printf("Enter text input file name: ");
            scanf("%s", &inpCmdFileName);
            checkFile = checkInpCmdFileName(inpCmdFileName);
            if (checkFile == 0) {
                fpCmd = fileOpen(inpCmdFileName, textReadMode);
                if (fpCmd == NULL) { //file cannot be open
                    checkFile = 1;
                    printf("Invalid file name %s\n", inpCmdFileName);
                }
            }
        } while (checkFile != 0);
        

    //prompt for outputfile name
    // 
            do {
                printf("Enter output file name: ");
                scanf("%s", &outputFileName);
                checkFile = checkOutputFileName(inpCmdFileName, outputFileName);
                if (checkFile == 0) {
                    fpOut = fileOpen(outputFileName, textWriteMode);
                    if (fpOut == NULL) { //file cannot be open
                        checkFile = 1;
                        printf("Invalid file name %s\n", outputFileName);
                    }
                }
            } while (checkFile != 0);


    //open and load values from binary file
            inpCount = getNumIntFromInpFile(inpValsFileName);
            inpValCount = fread(inpValArray, sizeof(int), inpCount , fpVals);

            fclose(fpVals);
   
    //loop and go through each command
            //for each command, do the correct execution
            curValArrayIndex = 0; //current index
            do {
                fgetsResult =  fgets(cmdLine, MAXLINE, fpCmd);
                if (fgetsResult != NULL) {
                    cmdVal = splitCommandLine(cmdLine, cmd); //split command line into command and value

                    if (strcmp(cmd, "exit") == 0) {
                        fclose(fpOut);
                        fclose(fpCmd);
                        break;
                    }

                    if (strcmp(cmd, "copy") == 0) { //copy command
                        fprintf(fpOut, "Copied %d values: ", cmdVal);
                        for (int j = 0; j < cmdVal; j++) {
                            fprintf(fpOut, "%d ", inpValArray[curValArrayIndex]);
                            curValArrayIndex++;
                        }
                        fprintf(fpOut, "\n");
                    }

                    if (strcmp(cmd, "reverse") == 0) { //reverse command
                        fprintf(fpOut, "Reversed %d values: ", cmdVal);
                        for (int j = 0; j < cmdVal; j++)
                            tempReverse[j] = inpValArray[j + curValArrayIndex];
                        for (int j = cmdVal - 1; j > 0; j--)
                            fprintf(fpOut, "%d ", tempReverse[j]);
                        curValArrayIndex = curValArrayIndex + cmdVal;
                        fprintf(fpOut, "\n");
                    }

                    if (strcmp(cmd, "sort") == 0) { //sort command
                        fprintf(fpOut, "Sorted %d values: ", cmdVal);
                        for (int j = 0; j < cmdVal; j++)
                            tempSort[j] = inpValArray[j + curValArrayIndex];
                        sortArray(tempSort, cmdVal);
                        for (int j = 0; j < cmdVal; j++)
                            fprintf(fpOut, "%d ", tempSort[j]);
                        curValArrayIndex = curValArrayIndex + cmdVal;
                        fprintf(fpOut, "\n");
                    }

                    if (strcmp(cmd, "median") == 0) { //median command
                        for (int j = 0; j < cmdVal; j++)
                            tempSort[j] = inpValArray[j + curValArrayIndex];
                        medianVal = median(tempSort, cmdVal);
                        for (int j = 0; j < cmdVal; j++)
                            fprintf(fpOut, "%d ", tempSort[j]);
                        curValArrayIndex = curValArrayIndex + cmdVal;
                        fprintf(fpOut, "Median of %d values: %0.1lf", cmdVal, medianVal);
                        fprintf(fpOut, "\n");
                    }

                }
            } while (fgetsResult != NULL);

}
