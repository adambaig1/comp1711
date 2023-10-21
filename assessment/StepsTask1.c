#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



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
    FILE *fp;
    fp = fopen("FitnessData_2023.csv", "r");

    if (fp == NULL){
        printf("unable to open file");
    } 

    char mystr [27];

    int i = 0;
    while (i<2){
        fgets(mystr, 27, fp);

        char _date[11];
        char _time[6];
        char _steps[10];

        tokeniseRecord(mystr, ",", _date, _time, _steps);

        printf("Date: %s\n", _date);
        printf("Time: %s\n", _time);
        printf("Steps: %s\n", _steps);   
        i++;   
    }
    char c;
    int count;

    while (getc(fp) != EOF)
        if (c == '\n')
            count = count + 1;


    printf("%d\n",count);



    return 0;
}