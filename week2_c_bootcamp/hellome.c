#include <stdio.h>
int main(){
    // setting up a string w max char. count of 15
    char name[15];
    //user prompt
    printf("hello, please enter your name:");
    //grabs user responss
    scanf("%s", name);
    //outputs the name
    printf("your name is %s\n", name);
return 0;

}
