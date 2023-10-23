#include <stdio.h>
#include "utils.h"

int main () {
    char* filename = "d.txt";
    FILE *file = open_file(filename, "w");

    int num;
    printf("how many numbers do you want to enter? ");
    scanf("%d", &num);


    int arr[num];
    int t = 0;
    printf("enter number: ");
    for (int i = 0; i<num; i++){
        scanf("%d",&arr[i]);
        fprintf(file, "%d\n", arr[i]);
        t = t + arr[i];
    }

    int mean = t/num;
    fprintf(file, "%d\n", mean);

    int c;
    printf("how many strings do you want to enter? ");
    scanf("%d\n", &c);

    char arr1[128] [c];
    printf("enter string: ");
    for(int i = 0; i<c; i++){
        scanf("%s\n", arr1[i]);
        fprintf(file, "%s\n", arr1[i]);
    }






    fclose(file);
    return 0;
}