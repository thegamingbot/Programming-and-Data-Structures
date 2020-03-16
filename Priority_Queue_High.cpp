#include<stdio.h>
#include<stdlib.h>

struct Heap
{
	int a[2][50];
	int r; 
};

struct Heap Heap;
void insert(int x, int p);
int del();
void swap(int* x, int* y);

int main()
{
	Heap.r = 0;
	insert(1, 15);
	insert(2, 500);
	insert(3, 50);
	insert(4, 70);
	insert(5, 1);
	insert(6, 5);
		
	for(int i = 1;i <= Heap.r;++i)
		printf("%d  %d\n", Heap.a[0][i], Heap.a[1][i]);
	printf("\n%d\n", del());
	for(int i = 1;i <= Heap.r;++i)
		printf("%d  %d\n", Heap.a[0][i], Heap.a[1][i]);
}

void insert(int x, int p)
{
	Heap.r++;
	Heap.a[0][Heap.r] = p;
	Heap.a[1][Heap.r] = x;
	int t = Heap.r;
	while((t/2 >= 1) && (Heap.a[0][t] >= Heap.a[0][t / 2]))
	{
		swap(&Heap.a[0][t], &Heap.a[0][t/2]);
		swap(&Heap.a[1][t], &Heap.a[1][t/2]);
		t /= 2;
	}
}

int del()
{
	int x = Heap.a[1][1];
	Heap.a[0][1] = Heap.a[0][Heap.r];
	Heap.a[1][1] = Heap.a[1][Heap.r];
	Heap.r--;
	int t = 1;
	int i;
	while(2*t <= Heap.r)
	{
		if(2*t + 1 <= Heap.r)
		{
			if(Heap.a[0][2*t] > Heap.a[0][2*t + 1])
				i = 2*t;
			else 
				i = 2*t+1;
		}
		else
			i = 2*t;
		if(Heap.a[0][t] < Heap.a[0][i])
		{
			swap(&Heap.a[0][t], &Heap.a[0][i]);
			swap(&Heap.a[1][t], &Heap.a[1][i]);
			t = i;
		}
		else
			break;
	}
	return x;
}

void swap(int* x, int* y)
{
	int a;
	a = *x;
	*x = *y;
	*y = a;
}
