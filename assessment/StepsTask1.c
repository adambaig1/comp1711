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
    FILE *file;
    file = fopen("FitnesData_2023.csv","r");

    if (file == NULL){
        printf("error accessing file\n");
        return 1;
    }

    FITNESS_DATA data[3];

    int read = 0;
    int record = 0;

    do
    {
        read = fscanf(file,
                        "%10s,%5s,%d\n", &data[record].date, &data[record].time, &data[record].steps);

        if (read == 3){
            record ++;
        }
        else if (read != 3 && !feof(file)){
            printf("file format is incorrect\n");
            return 1;
        }

        if (ferror(file)){
            printf("error reading file\n");
            return 1;
        }

    } while (!feof(file));
    
    fclose(file);

    printf("\n%d reccords read\n\n", record);

    for (int i = 0; i < record; i++){
        printf("%s/%s/%d", data[i].date, data[i].time, data[i].steps);

    }
    printf("\n");





    return 0;
}