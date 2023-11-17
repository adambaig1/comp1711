#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

FILE *open_file(char *filename, char *mode)
{
    FILE *input = fopen(filename, "r");
    if (!input)
    {
        printf("Error: File could not be opened\n");
    }
}

int count_line(FILE *inputFile){
	int count = 0;
	char str[100];

    while(fgets(str, 100, inputFile) != NULL)
    {
        count++;
    }

	return count;
}


#endif // FITNESS_DATA_STRUCT_H