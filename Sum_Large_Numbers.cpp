#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* nptr;
};

struct node* hptr1 = NULL;
struct node* hptr2 = NULL;
struct node* hptr3 = NULL;
struct node* hptr4 = NULL;
struct node* hptr5 = NULL;

int carry = 0;

void insert(struct node** ptr, int x, int pos);
void add(struct node** ptr1, struct node** ptr2);
void print(struct node* ptr);

int main()
{
	int m, n;
	printf("Enter the number of digits of the two numbers\n");
	scanf("%d %d", &m, &n);
	int a[100], b[100];
	printf("Enter the first number: \n");
	for(int i=0; i<m; i++)
	{
		printf("Enter a digit\n");
		scanf("%d", &a[i]);
	}
	printf("Enter the second number: \n");
	for(int i=0; i<n; i++)
	{
		printf("Enter a digit\n");
		scanf("%d", &b[i]);
	}
	for(int i = 0; i < m; i++)
		insert(&hptr1, a[i], 0);
	for(int i = 0; i < n; i++)
		insert(&hptr2, b[i], 0);
	if(m > n)
	{
		for(int i = n; i < m; i++)
			insert(&hptr2, 0, i);
	}
	else
	{
		for(int i = m; i < n; i++)
			insert(&hptr1, 0, i);
	}
	add(&hptr1, &hptr2);
	print(hptr3);
	printf("\n");
}

void insert(struct node** ptr, int x, int pos)
{
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	struct node* thptr = *ptr;
	temp->data = x;
	if(pos == 0)
	{
		temp->nptr = *ptr;
		*ptr = temp;
	}
	else
	{
		int i = 0;
		while(i<pos-1)
		{
			thptr = thptr->nptr;
			i++;
		}
		temp->nptr = thptr->nptr;
		thptr->nptr = temp;
	}
}

void add(struct node** ptr1, struct node** ptr2)
{
	struct node* thptr1 = *ptr1;
	struct node* thptr2 = *ptr2;
	while(thptr1 != NULL && thptr2 != NULL)
	{
		insert(&hptr3, (thptr1->data+thptr2->data+carry) % 10, 0);
		carry = (thptr1->data+thptr2->data+carry) / 10;
		thptr1 = thptr1->nptr;
		thptr2 = thptr2->nptr;
	}
	insert(&hptr3, carry, 0);
}

void print(struct node* ptr)
{
	struct node* thptr = ptr;
	while(thptr != NULL)
	{
		printf("%d", thptr->data);
		thptr = thptr->nptr;
	}
}
