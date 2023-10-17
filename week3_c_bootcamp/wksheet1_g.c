#include <stdio.h>

int main(){
    //1
    int option;
    printf("select options 1-5: ");
    scanf("%d",&option);

    switch (option)
    {
    case 1:
        printf("option one has been selected\n");
        break;
    case 2:
        printf("option two has been selected\n");
        break;        
    case 3:
        printf("option three has been selected\n");
        break;  
    case 4:
        printf("option four has been selected\n");
        break;  
    case 5:
        printf("option five has been selected\n");
        break;
    default:
        printf("invalid option!\n");
        break;
    }

    //2
    int num;
    int h;
    h = 1;
    while (h != 0)
    {
        printf("enter value: ");
        scanf("%d", &num);

        if (num == -1 ){
            printf("termination value entered, goodbye\n");
            h =0;
        }
        else if ( num >= 0 && num<=100)
        {
            printf("valid entry\n");
        }
        else{
            printf("invalid entry\n");
        }
        




    }
    

}