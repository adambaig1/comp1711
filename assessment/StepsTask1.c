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

    int count = 1;
    char current_c;

    while (current_c != EOF){
        current_c = fgetc(fp);
        if (current_c == '\n'){
            count++;
        }       
    }

    printf("Number of records in file: %d\n", count);

    FITNESS_DATA reccords[count];

    int c= 0;
    while(c<2){
        char date[11];
        char time[6];
        char steps[10];
        fgets(mystr, 27, fp);
        printf("%s", mystr);
        tokeniseRecord(mystr, ",", date, time, steps);

//        printf("%s\n", date);
//        printf("%s\n", time);
//        printf("%s\n", steps);

//        strcpy(reccords[c].date, date);
//        strcpy(reccords[c].time, time);
//        reccords[c].steps = atoi(steps);
        c++;
        
    }


    for(int c = 0; c<3; c++){
        printf("%s/%s/%d\n",reccords[c].date ,reccords[c].time ,reccords[c].steps);

    }


    return 0;
}