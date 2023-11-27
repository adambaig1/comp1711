#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
char filename[50];

char choice;
char str[100];
char date_[20];
char time_[20];
char steps_[20];
int count = 0;
FITNESS_DATA records[10000];
    
char date_[20];
char time_[20];
char steps_[20];

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }




// Complete the main function
int main() {

    while (1)
    {
        choice = 0;
        printf("A: Specify the filename to be imported\n");                     
        printf("B: Display the total number of records in the file\n");                    
        printf("C: Find the date and time of the timeslot with the fewest steps\n");                     
        printf("D: Find the date and time of the timeslot with the largest number of stepsl\n");                    
        printf("E: Find the mean step count of all the records in the file\n");       
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");                
        printf("Q: Quit\n");
        printf("Enter Choice: ");
        choice = getchar();
        while (getchar() != '\n');
        
        switch(choice)
        {
        case 'A':
        case 'a':
            printf("Input filename: ");
            scanf("%s",filename);

            FILE *fp = fopen(filename, "r");
            if (!fp)
            {
                printf("Error: File could not be opened\n");
                return 1;
            }
            
            break;

        case 'B':
        case 'b':
            printf("Total records: %d\n", count_line(fp));
            break;
            
        case 'C':
        case 'c':    
            while (fgets(str, 100, fp) != NULL)
            {
                tokeniseRecord(str,",",date_, time_, steps_);
                strcpy(records[count].date, date_);
                strcpy(records[count].time, time_);
                records[count].steps = atoi(steps_);
                count++;  
            }
            
            int min = records[0].steps;
            int c = 0;
            for (int x = 0; x <count; x++)
            {
                if (records[x].steps<min){
                    min = records[x].steps;
                    c = x;
                }
            }
            printf("Fewest steps: %s %s\n",records[c].date, records[c].time);

            break;
        case 'D':
        case 'd':

            break;
        case 'E':
        case 'e':


            break;

        case 'F':
        case 'f':


            break;

        case 'Q':
        case 'q':

            return 0;
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }


   return 0;
}

