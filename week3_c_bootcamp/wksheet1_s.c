#include <stdio.h>

int main(){
    //1
    int mark;
    printf("enter mark:");
    scanf("%d",&mark);

    if (mark>=70)
    {
        printf("%d is a distinction\n",mark);
    }
    else if (mark>=50)
    {
        printf("%d is a pass\n",mark);
    }
    else{
        printf("%d is a fail\n",mark);
    }

    //2
    int temp;
    printf("enter temperature: ");
    scanf("%d",&temp);

    if (temp <=40 && temp>=-10){
        printf("valid temperature\n");
    }
    else{
        printf("invalid temperature\n");
    }


}