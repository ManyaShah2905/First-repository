#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct __stack_node
{
void *data;
struct __stack_node *next;
}StackNode;
typedef struct __stack
{
int elementSize;
StackNode *top;
int size;
}Stack;
void initStack(Stack *stack,int elementSize)
{
stack->top=NULL;
stack->size=0;
stack->elementSize=elementSize;
}
int isEmpty(Stack *stack)
{
return stack->size==0;
}
void push(Stack *stack,const void *data)
{
StackNode *t;
t=(StackNode *)malloc(sizeof(StackNode));
t->data=(void *)malloc(stack->elementSize);
memcpy(t->data,data,stack->elementSize);
t->next=stack->top;
stack->top=t;
stack->size++;
}
void pop(Stack *stack,void *data)
{
StackNode *t;
t=stack->top;
stack->top=stack->top->next;
stack->size--;
memcpy(data,(const void *)t->data,stack->elementSize);
free(t->data);
free(t);
}
struct Student
{
int rollNumber;
char name[21];
};
int main()
{
int x;
Stack s;
struct Student student;
initStack(&s,sizeof(struct Student));
x=1;
while(x<=3)
{
printf("Enter roll number:");
scanf("%d",&student.rollNumber);
printf("Enter name:");
scanf("%s",student.name);
push(&s,(const void *)&student);
x++;
}
while(!isEmpty(&s))
{
pop(&s,(void *)&student);
printf("Roll Number %d,Name %s\n",student.rollNumber,student.name);
}
return 0;
}