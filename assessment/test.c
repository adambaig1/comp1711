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
char line_buffer[100];
int count=0;
char my_date[11];
char my_time[6]; 
char my_steps[8];
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
 
    char* filename = "FitnessData_2023.csv";
    FILE *file = fopen("FitnessData_2023.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    FITNESS_DATA fitness [1000] = {};
    while (fgets(line_buffer,100,file) != NULL){
        tokeniseRecord(line_buffer,",",my_date,my_time,my_steps);
        strcpy(fitness[count].date, my_date);
        strcpy(fitness[count].time, my_time);
        fitness[count].steps = atoi(my_steps);
        count++;
        
    }
    printf("Number of records in file: %d\n",count);
    for (int j = 0; j <3; j++)
    {
        printf("%s/%s/%d\n",fitness[j].date,fitness[j].time,fitness[j].steps);
    }
    
    fclose(file);
    return 0;
}