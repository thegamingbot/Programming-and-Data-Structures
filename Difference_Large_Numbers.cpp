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
struct node* hptr6 = NULL;

int carry = 0;

void insert(struct node** ptr, int x, int pos);
void add(struct node** ptr1, struct node** ptr2);
void comp(struct node** ptr);
void reverse(struct node** ptr);
struct node* CopyList(struct node* hptr3);
void print(struct node* ptr);
void diff(struct node** ptr1, struct node** ptr2, int x);

int main()
{
	int m, n, x;
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
		x = m;
		for(int i = n; i < m; i++)
			insert(&hptr2, 0, i);
	}
	else
	{
		x = n;
		for(int i = m; i < n; i++)
			insert(&hptr1, 0, i);
	}
	diff(&hptr1, &hptr2, x);	
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
		carry = (thptr1->data + thptr2->data + carry) / 10;
		thptr1 = thptr1->nptr;
		thptr2 = thptr2->nptr;
	}
	insert(&hptr3, carry, 0);
}

void diff(struct node** ptr1, struct node** ptr2, int x)
{	
	comp(ptr2);
	add(ptr1, &hptr4);
	hptr3 = hptr3->nptr;
	insert(&hptr5, carry, 0);
	for(int i = 1; i < x; i++)
		insert(&hptr5, 0, 0);
	hptr6 = CopyList(hptr3);
	hptr3 = NULL;
	reverse(&hptr5);
	reverse(&hptr6);
	if(carry != 0)
	{
		carry = 0;
		add(&hptr5, &hptr6);
	}
}

struct node* CopyList(struct node* hptr3)
{
	if (hptr3 == NULL)
		return NULL;
	else 
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->data = hptr3->data;
		temp->nptr = CopyList(hptr3->nptr);
		return temp;
	}
}

void reverse(struct node** ptr) 
{ 
    struct node* prev = NULL; 
    struct node* current = *ptr; 
    struct node* next = NULL; 
    while (current != NULL)
	{
        next = current->nptr; 
        current->nptr = prev; 
        prev = current; 
        current = next; 
    } 
    *ptr = prev; 
}

void comp(struct node** ptr)
{
	struct node* thptr = *ptr;
	while(thptr != NULL)
	{
		insert(&hptr4, 9-thptr->data, 0);
		thptr = thptr->nptr;
	}
	reverse(&hptr4);
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
