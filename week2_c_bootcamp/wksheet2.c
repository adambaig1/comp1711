#include <stdio.h>
#include <limits.h>

int main(){
    //1
    int arr[] = {1,2,3,4,5};
    int sum = 0;
    int length = 0;

    for (int i = 0; i<5 ; i++){
        sum = sum + arr[i];
    }
    printf("the sum of the array is %d\n", sum);

    //2
    int arr2[5];
    int c;
    for (int i = 5; i>=0; i--){
        c = arr[i];
        for (int z = 0; z<5; z++){
            arr2[z]=c;
        }
    }

    for (int r = 5; r<5; r++){
        printf("%d\n", arr2[r]);
    }
    



return 0;
}