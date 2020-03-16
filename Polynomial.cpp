#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct polynomial {
	int a[100];
	int size;
};

void Insert (struct polynomial *pc, int x, int pos);

int Simplify (struct polynomial *pc, struct polynomial *pv);

int main()
{
	struct polynomial c, *pc, v, *pv;
	pc = &c;
	pv = &v;
	pc->size = 0;
	pv->size = 0;
	int b, y, value, m[100];
	printf("Enter the highest power of the polynomial\n");
	scanf("%d", &b);
	for(int i = b; i>=0; i--)
	{
		printf("Enter the coefficient of x^%d :\t", i);
		scanf("%d", &m[i]);
	}
	for(int i = b; i>=0; i--)
	{
		Insert (pc, m[i], 0);
	}
	printf("Enter the value of x: \t");
	scanf("%d", &y);
	for(int i = b; i>=0; i--)
	{
		Insert(pv, pow(y, i), 0);
	}
	value = Simplify(pc, pv);
	printf("The value of the polynomial at x = %d is %d\n", y, value);
	return 0;
}
void Insert (struct polynomial *pc, int x, int pos)
{
	for(int i = pc->size-1; i>=pos ;i--)
	{
		pc->a[i+1] = pc->a[i];
	}
	pc->a[pos] = x;
	pc->size += 1;
}

int Simplify (struct polynomial *pc, struct polynomial *pv)
{
	int sum = 0;
	for (int i = pc->size-1; i>=0 ;i--)
	{
		sum = sum + (pc->a[i] *pv->a[i]);
	}
	return sum;
}
