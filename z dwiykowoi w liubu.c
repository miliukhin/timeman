#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
char ch[13]={1,1,0,1,1,0,0,1,1,0,1,1,1};
int a=0;
for(int i=0,j=12;i<13;i++,j--)
{
    a+= ch[i]*pow(2,j);
}
printf("\n%d",a);
return 0;
}
