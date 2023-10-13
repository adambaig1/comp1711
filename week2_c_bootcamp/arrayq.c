#include <stdio.h>
int main(){
    //1
    char string[] = "Hello";
    int i = sizeof(string);
    while (i>=0){
        printf("%c\n",string[i]);
       i--;
   }

    printf("%c\n",string[5]);
    return 0;

}