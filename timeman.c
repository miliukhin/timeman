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
   printf("%0.15f",korin(2));
}

