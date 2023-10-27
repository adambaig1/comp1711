#include <stdio.h>
#include "utils.h"

int main () {
    //bronze
    FILE *fp = fopen ("squares.dat", "w"); 
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int num;
    printf("enter the number to square numbers up to: ");
    scanf("%d",&num);

    for(int i = 1; i<=num; i++){
        fprintf(fp, "%d\n", i*i);
    }

    fclose(fp);

    //silver
    FILE *fptr = fopen("squares.dat", "r");
    
    if (fptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char num1[20];
    int num2;
    int arr[num];
    int ct = 0;

    for (int i = 0; i<num; i++){
        fgets(num1, 20, fptr);
        arr[i]= atoi(num1);
        ct = ct+1;
        printf("%d\n",arr[i]);
    } 

    float mean;
    int t = 0;

    for(int i = 0; i<ct; i++){
        t= t + arr[i];
    }

    float f = t/ct ;

    printf("%f\n", f);



    return 0;
}