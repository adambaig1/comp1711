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

    //this prints out an error message if the file cannot be opened
    if (fp == NULL){
        return 1;
    } 

    //count is the variable used to count the records in the file, current_c is used to determine when the end of a record is
    int count = 0;
    char c[30];
    //this while loop iterates until the end of the file, it uses the fgets function which goes through each line in the csv
    //it increments the counter if there isn't a blank or NULL line
    while (fgets(c, 30, fp) != NULL){
        count++;
    }
    //this prints out the number of records in the file
    printf("Number of records in file: %d", count);
    printf("\n");
    fclose(fp);

    //I had to create a new file pointer as the data the old one was collecting was corrupting
    FILE *fptr;
    fptr = fopen("FitnessData_2023.csv", "r");
    //this initializes a typedef array holding all the records, with the size beign variable to the size of the csv file
    FITNESS_DATA records[count];

    //this initializes the string which is used to store the records in the csv  
    char str[30];
    //this for loop starts from 0 to the length of the file
    //it gets the line of the file via the fegts function, then uses the tokenisRecord function to create tokens
    //these tokens are then stored in the records array
    for (int i = 0; i<count; i++){
        char date[11];
        char time[6];
        char steps[5];
    
        fgets(str, 30, fptr);
        if (str != NULL){
            tokeniseRecord(str, ",", date, time, steps);

            strcpy(records[i].date, date);
            strcpy(records[i].time, time);
            records[i].steps = atoi(steps);            
        }
    }

    //this for loop prints out the first three stored reccords in the array
    for (int x = 0; x<3; x++){
        printf("%s/%s/%d", records[x].date, records[x].time, records[x].steps);
        printf("\n");

    }

    //this closes the filepointer
    fclose(fptr);
    return 0;
}