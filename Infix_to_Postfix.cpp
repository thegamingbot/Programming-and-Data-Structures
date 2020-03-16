#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Stack
{
	int top;
	int capacity;
	int* array;
};

struct Stack* createStack(int capacity)
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));
	return stack;
}

int isEmpty(struct Stack* stack);
char peek(struct Stack* stack);
char pop(struct Stack* stack);
void push(struct Stack* stack, char op);
int Prec(char ch); 
int infixToPostfix(char* exp);

int main()
{
	char exp[50];
	printf ("Enter the infix expression:  ");
	scanf ("%s", exp);
	infixToPostfix(exp);
	return 0;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1 ;
}

char peek(struct Stack* stack)
{
	return stack->array[stack->top];
}

char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--];
} 

void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}

int Prec(char ch)
{
	switch (ch)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
} 

int infixToPostfix(char* exp)
{
	int i, k;
	int a, b, c;
	struct Stack* stack = createStack(strlen(exp));
	for (i = 0, k = -1; exp[i]; ++i)
	{
		if (isdigit(exp[i]))
			exp[++k] = exp[i];
		else if (exp[i] == '(')
			push(stack, exp[i]);
		else if (exp[i] == ')')
		{
			while (!isEmpty(stack) && peek(stack) != '(')
				exp[++k] = pop(stack);
			if (!isEmpty(stack) && peek(stack) != '(')
				return -1;
			else
				pop(stack);
		}
		else
		{
			while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
				exp[++k] = pop(stack);
			push(stack, exp[i]);
		}
	}
	while (!isEmpty(stack))
		exp[++k] = pop(stack);
	exp[++k] = '\0';
	printf("The postfix expression:  ");
	printf("%s", exp);
}
