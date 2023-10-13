#include <stdio.h>
#include <limits.h>

int main(){
    //ex 1
    printf("Hello, World!\n");

    //ex 2
    int num1;
    int num2;
    int num3;

    printf("enter number 1:");
    scanf("%d", &num1);
    printf("enter number 2:");
    scanf("%d", &num2);

    num3 = num1 + num2;

    printf("your sum is %d\n", num3);

    //ex 4
    float radius;
    float area;
    float pi = 3.14;

    printf("enter the radius:");
    scanf("%f",&radius);

    area = pi * radius * radius;
    printf("your area is %g\n", area);

    //ex5
    char var1;
    char var2;

    printf("enter the first variable:");
    scanf("%c",&var1);

    printf("enter the second variable:");
    scanf("%c",&var2);


    printf("first variable: %c\n", var2);
    printf("second variable: %c\n", var1);

    //ex6
    int num;
    printf("enter number to be evaluated if it is odd or even: ");
    scanf("%d", &num);

    if (num % 2 == 0){
        printf("your number is even\n");
    }

    else{
        printf("your number is odd\n");
    }


    //ex8
    int no1, factorial;
    factorial = 1;
    printf("enter a number to be factorialised: ");
    scanf("%d",&no1);

    for (int i = 1; i<=no1; i++){
        factorial = factorial *i;


    }
    printf("your number factorialised is: %d\n", factorial);




return 0;
}