#include <stdio.h>
#include<string.h>
//Система числення
#define N 8
int main(){
 int a=0xb4;
printf("%d\n",a);

 //printf ("%d", a%8);
// printf("\n%d",a/8);
 for(int i=0;a>0;i++)
 {
    printf("%d    ",a);
    printf("%d\n",a % N);
    a=a/N;

 }
 printf("%d    ",a);
 printf("%d\n",a % N);
 return 0;
}



