#include <stdio.h>
#include <limits.h>

int main(){
    //1
    int arr[] = {1,2,3,4,5};
    int sum = 0;
    int length = 0;

    while(arr[length] != "\0"){
        length++;
    }

    for (int i = 0; i<length ; i++){
        sum = sum + arr[i];
    }
    printf("the sum of the array is %d\n", sum);

    //2
    



return 0;
}