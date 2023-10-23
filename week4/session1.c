#include <stdio.h>

int main(){
    //starter activity
    int arr[10];
    float m;
    float t;
    for(int i =0; i<=9; i++){
        printf("enter number:");
        scanf("%d",&arr[i]);
        t= t+arr[i];
    }

    m= t/10;

    printf("mean is %f\n",m);

    



}