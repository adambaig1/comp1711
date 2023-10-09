#include <stdio.h>
int main(){
   float side1;
   float side2;
   float area;
   
   printf("what is the length of side 1?");
   scanf("%f",&side1);
   printf("what is the length of side 2?");
   scanf("%f",&side2);

   area = side1 * side2;
   printf("your area is %g\n", area);

return 0;
}