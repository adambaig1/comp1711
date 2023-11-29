#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
char filename[50];
char line[50];
char choice;
char str[100];
char date_[20];
char time_[20];
char steps_[20];
int count = 0;
FITNESS_DATA min;
FITNESS_DATA max;
int streak;
int mean;
FITNESS_DATA records[10000];
int l_num;
int strk_count = 0;
int l;

    
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
        //these are all the menu options to choose from
        printf("Menu Options:\n");
        printf("A: Specify the filename to be imported\n");                     
        printf("B: Display the total number of records in the file\n");                    
        printf("C: Find the date and time of the timeslot with the fewest steps\n");                     
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");                    
        printf("E: Find the mean step count of all the records in the file\n");       
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");                
        printf("Q: Quit\n");
        printf("Enter Choice: ");
        //this gets the user input without the newline
        choice = getchar();
        while (getchar() != '\n');

        //this switch case is for the user input
        switch(choice)
        {
        case 'A':
        case 'a':

            //resets the lin counter everytime a new file is inputted
            count = 0;

            //gets the filename from user input
            printf("Input filename: ");
            fgets(line, 50, stdin);
            sscanf(line, " %s ", filename);

            //opens the file, and reports any errors
            FILE *fp = fopen(filename, "r");
            if (!fp)
            {
                printf("Error: File could not be opened\n");
                return 1;
            }
            
            while (fgets(str, 100, fp) != NULL)
            {
                tokeniseRecord(str,",",date_, time_, steps_);
                strcpy(records[count].date, date_);
                strcpy(records[count].time, time_);
                records[count].steps = atoi(steps_);
                count++;  
            }

            fclose(fp);
            break;

        case 'B':
        case 'b':            
            printf("Total records: %d\n", count);
            break;
            
        case 'C':
        case 'c':    
            min = find_min(records, count);

            printf("Fewest steps: %s %s\n",min.date, min.time);

            break;
        case 'D':
        case 'd':
            max = find_max(records, count);
            printf("Largest steps: %s %s\n",max.date, max.time);          

            break;
        case 'E':
        case 'e':
            mean = find_mean(records, count);
            
            printf("Mean step count: %d\n", mean);

            break;

        case 'F':
        case 'f':

            for(int i = 0; i<count; i++)
            {
                if (records[i].steps > 500)
                {

                    if (records[i+1].steps > 500)
                    {
                        l++;   
                    }
                    else
                    {
                        if(l+1> strk_count)
                        {
                            strk_count = l; 
                            l_num = i;
                        }

                        l=0;
                    }
                }
            }

            printf("Longest period start: %s %s\n", records[l_num - strk_count].date, records[l_num - strk_count].time);
            printf("Longest period end: %s %s\n", records[l_num].date, records[l_num].time);

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

