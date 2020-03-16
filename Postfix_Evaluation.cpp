#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h>

struct Stack 
{ 
    int top; 
    int capacity; 
    int* array; 
};

struct Stack* createStack(int capacity);
int isEmpty(struct Stack* stack);
char pop(struct Stack* stack);  
void push(struct Stack* stack, char op);
int evaluatePostfix(char* exp);

int main() 
{ 
    char exp[20];
    printf ("Enter the expression:  ");
    scanf ("%s", exp);
    printf ("Postfix evaluation:  %d\n", evaluatePostfix(exp)); 
    return 0; 
}

struct Stack* createStack(int capacity)
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));  
    stack->top = -1; 
    stack->capacity = capacity; 
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
	return stack; 
} 

int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1 ; 
} 

char pop(struct Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--];
} 
  
void push(struct Stack* stack, char op) 
{ 
    stack->array [++stack->top] = op; 
} 

int evaluatePostfix(char* exp) 
{
    struct Stack* stack = createStack(strlen(exp)); 
    int i;
    for (i = 0; exp[i]; ++i) 
    {
        if (isdigit(exp[i])) 
            push(stack, exp[i] - '0');
        else
        { 
            int val1 = pop(stack); 
            int val2 = pop(stack); 
            switch (exp[i]) 
            { 
            	case '+': 
				{
					push(stack, val2 + val1);
					break;
				} 
    	        case '-':
    	        {
    	        	push(stack, val2 - val1);
					break;
				}
        	    case '*':
        	    {
        	    	push(stack, val2 * val1);
					break;
				}
            	case '/':
            	{
            		push(stack, val2/val1);
					break;
				}
            } 
        } 
    } 
    return pop(stack); 
}
