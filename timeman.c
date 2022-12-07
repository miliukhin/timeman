#include <stdio.h>
float korin(int a){
 float x=1;
 for(int i=0;i<50;i++)
{
    x=(x+a/x)/2;
}
 return x;
}
int main()
{
   int i;
    printf("Enter number, a to exit ");
    scanf("%i",&i);
    printf("%0.15f",korin(i));
    printf("\n");
   if(getchar()=='a')
   {
       return 0;
   }
   else main();
}

