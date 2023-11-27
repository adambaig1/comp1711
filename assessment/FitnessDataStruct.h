#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;


int count_line(FILE *fp){
	int count = 0;
	char str[100];

    while(fgets(str, 100, fp) != NULL)
    {
        count++;
    }

	return count;
}

#endif // FITNESS_DATA_STRUCT_H