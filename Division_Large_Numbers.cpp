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
struct node* hptr7 = NULL;
struct node* hptr8 = NULL;

int carry = 0;
int quo = 0;

void insert(struct node** ptr, int x, int pos);
void add(struct node** ptr1, struct node** ptr2);
void comp(struct node** ptr);
void reverse(struct node** ptr);
int compare(struct node** ptr1, struct node** ptr2);
struct node* CopyList(struct node* hptr3);
void print(struct node* ptr);
void diff(struct node** ptr1, struct node** ptr2, int x);
void divide(struct node** ptr1, struct node** ptr2, int key);

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
	divide(&hptr1, &hptr2, x);
	printf("%d", quo);
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

void divide(struct node** ptr1, struct node** ptr2, int key)
{
	hptr7 = CopyList(hptr1);
	hptr8 = CopyList(hptr2);
	reverse(&hptr7);
	reverse(&hptr2);
	while(compare(&hptr7, &hptr2))
	{
		reverse(&hptr7);
		reverse(&hptr2);
		diff(&hptr7, &hptr2, key);
		hptr7 = CopyList(hptr3);
		hptr7 = hptr7->nptr;
		hptr2 = NULL;
		hptr2 = CopyList(hptr8);
		hptr3 = NULL;
		reverse(&hptr2);
		print(hptr7);
		printf("\n");
		print(hptr2);
		printf("\n");		
		quo++;
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
	printf("\n");
	printf("%d\n\n", carry);
	if(carry != 0)
	{
		carry = 0;
		add(&hptr5, &hptr6);
	}
	
}

int compare(struct node** ptr1, struct node** ptr2)
{
	struct node* thptr1 = *ptr1;
	struct node* thptr2 = *ptr2;
	int x = 0;
	while(thptr1 != NULL && thptr2 != NULL)
	{
		if(thptr1->data > thptr2->data)
		{
			x = 1;
			break;
		}
		else if(thptr1->data < thptr2->data)
		{
			x = 2;
			break;
		}
		else
		{
			thptr1 = thptr1->nptr;
			thptr2 = thptr2->nptr;
		}	
	}
	return x;
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
