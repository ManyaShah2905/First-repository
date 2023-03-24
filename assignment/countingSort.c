#include<stdio.h>
#include<stdlib.h>
int main()
{
int C[100],B[15];
int x[9],y,largest;
int *g;
for(y=0;y<9;y++)
{
printf("Enter a number:");
scanf("%d",&x[y]);
}
largest=x[0];
y=0;
while(y<=8)
{
if(x[y]>largest)
{
largest=x[y];
}
y++;
}
printf("Largest is %d\n",largest);
int s=largest+1;
printf("%d",s); 
for(int i=0;i<=s;i++)
{
C[i]=0;
printf("%d\n",C[i]);
for(y=0;y<9;y++)
{
x[y[i]]=x[y[i]]+1;
}
}
printf("%d\n",x[y[i]]);
return 0;
}