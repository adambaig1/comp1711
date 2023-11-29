#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

//function to find min steps in the array
FITNESS_DATA find_min(FITNESS_DATA* records, int count )
{
    //sets initial min as the first element
    int min = records[0].steps;
    //c will be used to store the index of the min
    int c = 0;
    //for loop to cycle through all elements to compare is to the min
    //if smaller than the mine, it will become the new min
    for (int x = 0; x <count; x++)
    {
        if (records[x].steps<min){
            c = x;
        }
    }
    //returning the minimum record in array
	return records[c];

}

//function to find the max steps in the array
FITNESS_DATA find_max(FITNESS_DATA* records, int count )
{
    //initial max is set to the first element
    int max = records[0].steps;
    //v is used to store largest elements index
    int v = 0;
    for (int x = 0; x <count; x++)
    {
        if (records[x].steps>max){
            max = records[x].steps;
            v = x;
		}
    }
    //returns largest reccord in array
	return records[v];

}

int find_mean(FITNESS_DATA* records, int count)
{
    //total steps and the mean is initialised
    int total_step = 0;
	int mean_step;
    //for loop to cycle through all elements and them up to make the total
    for (int x = 0; x<count; x++)
    {
        total_step = total_step + records[x].steps;
    }

    mean_step = total_step / count;

	return mean_step;
}


#endif // FITNESS_DATA_STRUCT_H