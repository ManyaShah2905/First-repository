#include<string.h>
#include<stdlib.h>
struct __stack_node
{
void *ptr;
struct __stack_node *next;
};
struct __stack
{
struct __stack_node *top;
int size;
int elementSize;
};
void initStack(struct __stack *stack,int elementSize)
{
stack->top=NULL;
stack->size=0;
stack->elementSize=elementSize;
}
int push(struct __stack *stack,void *ptr)
{
struct __stack_node *node;
if(stack==NULL) return 0;
node=(struct __stack_node *)malloc(sizeof(struct __stack_node));
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
int pop(struct __stack *stack,void *ptr)
{
int j;
struct __stack_node *node;
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
int isEmpty(struct __stack *stack)
{
if(stack==NULL) return 1; //returning true because stack is empty
if(stack->size==0) return 1;
return 0;
}