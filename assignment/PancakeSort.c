#include<stdio.h>
int main()
{
int n;
printf("Number of elements in an array:");
scanf("%d",&n);
int x[n],y;
int largest;
int i,r;
int *tmp;
int size,start,end;
y=0;
while(y<n)
{
printf("Enter a number:");
scanf("%d",&x[y]);
y++;
}
largest=x[0];
for(int y=0;y<=size;y++)
{
if(x[y]>largest)
{
largest=x[y];
i=y;
}
}

for(int y=i;y>=0;y--)
{
printf("%d\n",x[y]);
}





/*
//reverse
start=0;
end=i;
while(start<end)
{
*tmp=x[start];
x[start]=x[end];
x[end]=*tmp;
start++;
end--;
}
start=0;
end=7;
while(start<end)
{
*tmp=x[start];
x[start]=x[end];
x[end]=*tmp;
start++;
end--;
}
size--;
}
*/

return 0;
}