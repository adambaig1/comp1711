#include <stdio.h>
#include <limits.h>

int main(){
    //ex 1
    printf("Hello, World!");

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
    int var1;
    int var2;

    printf("enter the first variable:");
    scanf("%d",&var1);

    printf("enter the second variable:");
    scanf("%d",&var2);

    var1 = var2;
    var2 = var1;



return 0;
}