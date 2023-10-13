#include <stdio.h>

int main(){
    //1
    int a;
    for (a=0; a<=20; a++){
        if (a%2 != 0){
            printf("%d\n",a);
        } 
    }

    //2
    int c;
    c=40;

    while (c>=0){
        if ( c%2 == 0 ){
            printf("%d\n",c);
        }
        c--;

    }

    //3
    int x;
    for (x=0; x<11; x++){
        printf("%d\n",x*x);

    }


    return 0;
}