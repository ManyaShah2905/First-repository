#include<stdio.h>								
#include<string.h>
#include<stdlib.h>
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
void initStack(Stack *stack,int elementSize)
{
stack->top=NULL;
stack->size=0;
stack->elementSize=elementSize;
}
int push(Stack*stack,void *ptr)
{
StackNode *node;
if(stack==NULL) return 0;
node=(StackNode *)malloc(sizeof(StackNode));
if(node==NULL) return 0; //unable to allocate memory
if(ptr!=NULL)
{
node->ptr=(void *)malloc(stack->elementSize);
if(node->ptr==NULL)
{
free(node);
return 0;
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
return 1;
}
int pop(Stack *stack,void *ptr)
{
int j;
StackNode *node;
if(stack==NULL) return 0;
if(stack->top==NULL) return 0;
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
return 1;
}
int isEmpty(Stack *stack)
{
if(stack==NULL) return 1; //returning true because stack is empty
if(stack->size==0) return 1;
return 0;
}
int intComparator(void *left,void *right)
{
return (*((int *)left))-(*((int *)right));
}
void merge(void *x,int es,int lb1,int ub1,int lb2,int ub2,int (*p2f)(void *,void *))
{
int size1,size2,size3;
void *tmp;
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
if(p2f(x+(i1*es),x+(i2*es))<0)
{
memcpy(tmp+(i3*es),(const void *)(x+(i1*es)),es);
i1++;
}
else
{
memcpy(tmp+(i3*es),(const void *)x+(i2*es),es);
i2++;
} 
i3++;
}
while(i1<=ub1)
{
memcpy(tmp+(i3*es),x+(i1*es),es);
i1++;
i3++;
}
while(i2<=ub2)
{
memcpy(tmp+(i3*es),x+(i2*es),es);
i2++;
i3++;
}
i3=0;
i1=lb1;
while(i1<=ub1)
{
memcpy(x+(i1*es),tmp+(i3*es),es);
i1++;
i3++;
}
i2=lb2;
while(i2<=ub2)
{
memcpy(x+(i2*es),tmp+(i3*es),es);
i2++;
i3++;
}
free(tmp);
}
void mergeSort(void *x,int lowerBound,int upperBound,int es,int (*p2f)(void *,void *))
{
struct LBUB
{
int lb,ub;
};
struct LBUB lbub;
int a,b,mid;
Stack stack1;
Stack stack2;
initStack(&stack1,sizeof(struct LBUB));
initStack(&stack2,sizeof(struct LBUB));
lbub.lb=lowerBound;
lbub.ub=upperBound;
push(&stack1,(void *)&lbub);
while(!isEmpty(&stack1))
{
pop(&stack1,(void *)&lbub);
push(&stack2,(void *)&lbub);
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
if(a<mid)
{
lbub.lb=a;
lbub.ub=mid;
push(&stack1,(void *)&lbub);
}
if(mid+1<b)
{
lbub.lb=mid+1;
lbub.ub=b;
push(&stack1,(void *)&lbub);
}
}
while(!isEmpty(&stack2))
{
pop(&stack2,(void *)&lbub);
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
merge(x,sizeof(int),a,mid,mid+1,b,p2f);
}
}
int main()
{
int *x,y,req;
printf("Enter requirement:");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number:");
scanf("%d",&x[y]);
}
mergeSort(x,0,req-1,sizeof(int),intComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}