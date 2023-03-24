#include<stdio.h>								
#include<string.h>
#include<stdlib.h>
#define SUCCESSFUL 1
#define FAILED 0
/*
Idea related to stack functions
*/
typedef struct __stack_node
{
void *ptr;
struct __stack_node *next;
}StackNode;
typedef struct __stack
{
StackNode *top;
int size;
int elementSize;
}Stack;
void initStack(Stack *stack,int elementSize,int *successful,int *error)
{
if(successful!=NULL) *successful=FAILED;
if(error) *error=0;
if(stack==NULL)
{
if(error) *error=1;
return;
}
if(elementSize<=0)
{
if(error) *error=2;
return;
}
stack->top=NULL;
stack->size=0;
stack->elementSize=elementSize;
if(successful) *successful=SUCCESSFUL;
}
void push(Stack*stack,void *ptr,int *successful,int *error)
{
StackNode *node;
if(successful) *successful=FAILED;
if(error) *error=0;
if(stack==NULL)
{
*error=1;
return;
}
node=(StackNode *)malloc(sizeof(StackNode));
if(node==NULL)//unable to allocate memory
{
if(error) *error=3;
return;
} 
if(ptr!=NULL)
{
node->ptr=(void *)malloc(stack->elementSize);
if(node->ptr==NULL)
{
free(node);
if(error) *error=3;
return;
}
memcpy(node->ptr,(const void *)ptr,stack->elementSize);
}
else
{
node->ptr=ptr;
}
node->next=stack->top;
stack->top=node;
stack->size++;
if(successful) *successful=SUCCESSFUL;
}
void pop(Stack *stack,void *ptr,int *successful,int *error)
{
int j;
StackNode *node;
if(successful) *successful=FAILED;
if(error) *error=0;
if(stack==NULL || ptr==NULL)
{
if(error) *error=1;
return;
}
if(stack->top==NULL)
{
if(error) *error=4;
return;
}
if(stack->top->ptr==NULL)
{
for(j=0;j<stack->elementSize;j++)
{
*((char *)(ptr+j))=(char)0;
}
}
else
{
memcpy(ptr,(const void *)stack->top->ptr,stack->elementSize);
}
node=stack->top;
stack->top=stack->top->next;
if(node->ptr!=NULL) free(node->ptr);
free(node);
stack->size--;
if(successful) *successful=SUCCESSFUL;
}
int isEmpty(Stack *stack,int *successful,int *error)
{
if(successful) *successful=FAILED;
if(error) *error=0;
if(stack==NULL) //returning true because stack is empty
{
if(error) *error=1;
return 1;
}
if(successful) *successful=SUCCESSFUL;
if(stack->size==0) return 1;
return 0;
}
void merge(int *x,int lb1,int ub1,int lb2,int ub2)
{
int size1,size2,size3;
int *tmp;
int i1,i2,i3;
size1=(ub1-lb1)+1;
size2=(ub2-lb2)+1;
size3=size1+size2;
tmp=(int *)malloc(sizeof(int)*size3);
i1=lb1;
i2=lb2;
i3=0;
while(i1<=ub1 && i2<=ub2)
{
if(x[i1]<x[i2])
{
tmp[i3]=x[i1];
i1++;
}
else
{
tmp[i3]=x[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
tmp[i3]=x[i1];
i1++;
i3++;
}
while(i2<=ub2)
{
tmp[i3]=x[i2];
i2++;
i3++;
}
i3=0;
i1=lb1;
while(i1<=ub1)
{
x[i1]=tmp[i3];
i1++;
i3++;
}
i2=lb2;
while(i2<=ub2)
{
x[i2]=tmp[i3];
i2++;
i3++;
}
free(tmp);
}
void mergeSort(void *x,int lowerBound,int upperBound)
{
struct LBUB
{
int lb,ub;
};
int isSuccessful,errorNumber;
struct LBUB lbub;
int a,b,mid;
Stack stack1;
Stack stack2;
initStack(&stack1,sizeof(struct LBUB),&isSuccessful,&errorNumber);
initStack(&stack2,sizeof(struct LBUB),&isSuccessful,&errorNumber);
lbub.lb=lowerBound;
lbub.ub=upperBound;
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
while(!isEmpty(&stack1,&isSuccessful,&errorNumber))
{
pop(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
push(&stack2,(void *)&lbub,&isSuccessful,&errorNumber);
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
if(a<mid)
{
lbub.lb=a;
lbub.ub=mid;
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
}
if(mid+1<b)
{
lbub.lb=mid+1;
lbub.ub=b;
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
}
}
while(!isEmpty(&stack2,&isSuccessful,&errorNumber))
{
pop(&stack2,(void *)&lbub,&isSuccessful,&errorNumber);
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
merge(x,a,mid,mid+1,b);
}
}
int main()
{
int x[10],y;
for(y=0;y<=9;y++)
{
printf("Enter a number:");
scanf("%d",&x[y]);
}
mergeSort(x,0,9);
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}