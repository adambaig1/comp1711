#include <stdio.h>

int main(){
    //1
    int num1;
    printf("enter a number:");
    scanf("%d",&num1);

    if (num1>0)
    {
        printf("%d is positive\n",num1);

    }
    else if (num1<0)
    {
        printf("%d is negative\n", num1);

    }
    else{
        printf("number is zero\n");
    }

    //2
    int num2;
    printf("enter a number:");
    scanf("%d",&num2);

    if (num2 % 5 == 0 && num2 % 4 == 0){
        printf("number is divisble by both 4 and 5\n");
    }
    else if (num2 % 5 == 0 )
    {
        printf("number is only divisible by 5\n");
    }
        else if (num2 % 4 == 0 )
    {
        printf("number is only divisible by 4\n");
    }
    else{
        printf("number is neither divisible by 5 or 4\n");
    }
    



}