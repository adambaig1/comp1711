#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//by Adam Baig (Student no. = 201696916)

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
//count is used to count the number of lines in the csv
//str is the string I'll use to put the lines of csv in
//date_, time_, and steps_ are tokens of the csv string that has been read
int count = 0;
char str[100];
char date_[11];
char time_[6];
char steps_[5];


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
    //this initializes the file pointer and sets it to the csv file that is to be read
    FILE *fp;
    fp = fopen("FitnessData_2023.csv", "r");

    //this outputs an error message if the file cannot be opened
    if (fp == NULL){
        printf("Error opening file");
        return 1;
    } 

    //this initialises the array records to have a set length of 10000
    FITNESS_DATA records[10000];

    //this while loop cycles through the entire csv file until it reaches an empty line
    //it makes the inputted string into tokens
    //it then enters the value in the struct array, in its correct format
    //then it increments the counter
    while (fgets(str, 100, fp) != NULL){
        tokeniseRecord(str,",",date_, time_, steps_);
        strcpy(records[count].date, date_);
        strcpy(records[count].time, time_);
        records[count].steps = atoi(steps_);  
        count++;
    }
    
    //outputs the number of records in the file
    printf("Number of records in file: %d\n",count);
    //this for loop outputs the first three stored reccords in the array
    for (int x = 0; x <3; x++)
    {
        printf("%s/%s/%d\n",records[x].date,records[x].time,records[x].steps);
    }

    fclose(fp);
    return 0;
}