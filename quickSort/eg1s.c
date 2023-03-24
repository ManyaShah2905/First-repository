#include<stdio.h>
#include<stdlib.h>
struct Node
{
int lb,ub;
struct Node *next;
};
struct Node *top;
int isEmpty()
{
return top==NULL;
}
void push(int lowerBound,int upperBound)
{
struct Node *t;
t=(struct Node *)malloc(sizeof(struct Node));
t->lb=lowerBound;
t->ub=upperBound;
t->next=top;
top=t;
}
void pop(int *lowerBound,int *upperBound)
{
struct Node *t;
*lowerBound=top->lb;
*upperBound=top->ub;
t=top;
top=top->next;
free(t);
}
int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb]) e++;
while(x[f]>x[lb]) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
}
}
return f;
}
void quickSort(int *x,int lowerBound,int upperBound)
{
int lb,ub,pp;
push(lowerBound,upperBound);
while(!isEmpty())
{
pop(&lb,&ub);
pp=findPartitionPoint(x,lb,ub);
if(pp+1<ub) push(pp+1,ub);
if(lb<pp-1) push(lb,pp-1);
}
}
int main()
{
int *x,req,y;
top=NULL;
printf("Enter requirement:");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number:");
scanf("%d",&x[y]);
}
quickSort(x,0,req-1);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}
