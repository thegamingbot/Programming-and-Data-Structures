#include<stdio.h>
#include<stdlib.h>

struct Heap
{
	int a[50];
	int r; 
};

struct Heap Heap;
void insert(int p);
int del();
void swap(int* x, int* y);

int main()
{
	Heap.r = 0;
	insert(15);
	insert(500);
	insert(50);
	insert(70);
	insert(1);
	insert(5);
		
	for(int i = 1;i <= Heap.r;++i)
		printf("%d ", Heap.a[i]);
	printf("\n%d\n", del());
	for(int i = 1;i <= Heap.r;++i)
		printf("%d ", Heap.a[i]);
}

void insert(int p)
{
	Heap.r++;
	Heap.a[Heap.r] = p;
	int t = Heap.r;
	while((t/2 >= 1) && (Heap.a[t] >= Heap.a[t / 2]))
	{
		swap(&Heap.a[t], &Heap.a[t/2]);
		t /= 2;
	}
}

int del()
{
	int x = Heap.a[1];
	Heap.a[1] = Heap.a[Heap.r];
	Heap.r--;
	int t = 1;
	int i;
	while(2*t <= Heap.r)
	{
		if(2*t + 1 <= Heap.r)
		{
			if(Heap.a[2*t] > Heap.a[2*t + 1])
				i = 2*t;
			else 
				i = 2*t+1;
		}
		else
			i = 2*t;
		if(Heap.a[t] < Heap.a[i])
		{
			swap(&Heap.a[t], &Heap.a[i]);
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
