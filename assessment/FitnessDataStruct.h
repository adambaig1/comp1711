#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

FITNESS_DATA find_min(FITNESS_DATA* records, int count )
{
    int min = records[0].steps;
    int c = 0;
    for (int x = 0; x <count; x++)
    {
        if (records[x].steps<min){
            c = x;
        }
    }

	return records[c];

}

FITNESS_DATA find_max(FITNESS_DATA* records, int count )
{
    int max = records[0].steps;
    int v = 0;
    for (int x = 0; x <count; x++)
    {
        if (records[x].steps>max){
            max = records[x].steps;
            v = x;
		}
    }

	return records[v];

}

int find_mean(FITNESS_DATA* records, int count)
{
    int total_step = 0;
	int mean_step;
    for (int x = 0; x<count; x++)
    {
        total_step = total_step + records[x].steps;
    }

    mean_step = total_step / count;

	return mean_step;
}


#endif // FITNESS_DATA_STRUCT_H