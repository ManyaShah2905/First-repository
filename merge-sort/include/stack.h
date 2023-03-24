typedef struct __stack_node *StackNode;
typedef struct __stack *Stack;
void initStack(Stack *stack,int elementSize);
int push(Stack *stack,void *ptr);
int pop(Stack *stack,void *ptr);
int isEmpty(Stack *stack);