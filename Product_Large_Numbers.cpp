#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* nptr;
};

struct node* hptr1 = NULL;
struct node* hptr2 = NULL;
struct node* hptr3 = NULL;
struct node* hptr[100];

void insert(struct node** ptr, int x, int pos);
void multiply();
void reverse(struct node** ptr);
int count(struct node** ptr);
void print(struct node* ptr);

int main()
{
	for(int i = 0; i < 100; i++)
	{
		hptr[i] = NULL;
	}
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
	multiply();
	print(hptr3);
	printf("\n");
	return 0;
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

void multiply()
{
	struct node* thptr1 = hptr1;
	struct node* thptr2 = hptr2;
	struct node* thptr3 = hptr3;
	struct node* thptr[100];
	for(int i = 0; i < 100; i++)
		thptr[i] = hptr[i];
	int m = count(&hptr1);
	int n = count(&hptr2);
	int z;
	for(int i = 0; i < m; i++)
	{		
		for(int a = 0; a < 100; a++)
			thptr[a] = hptr[a];
		thptr2 = hptr2;
		while(thptr2 != NULL)
		{
			insert(&hptr[i], (thptr1->data*thptr2->data), 0);
			thptr2 = thptr2->nptr;
		}
		reverse(&hptr[i]);
		for(int k = 0; k < i; k++)
		{
			insert(&hptr[i], 0 , 0);
		}
		z = count(&hptr[i]);
		for(int k = z; k < m + n - 1; k++)
		{
			insert(&hptr[i], 0 , k);
		}
		thptr1 = thptr1->nptr;
	}
	int c = 0;
	for(int i = 0; i < 100; i++)
		thptr[i] = hptr[i];
	for(int j = 0; j < m + n - 1; j++)
	{
		c = 0;
		for(int i = 0; i < m; i++)
		{
			c = c + thptr[i]->data;
			thptr[i] = thptr[i]->nptr;
		}
		insert(&hptr3, c, 0);
	}
	reverse(&hptr3);
	thptr3 = hptr3;
	int carry = 0;
	int p;
	while(thptr3 != NULL)
	{
		p = (thptr3->data + carry) % 10;
		carry = (thptr3->data + carry) / 10;
		thptr3->data = p;
		thptr3 = thptr3->nptr;
	}
	reverse(&hptr3);
}

int count(struct node** ptr) 
{
	struct node* thptr = *ptr;
    if (thptr == NULL) 
        return 0;
    return 1 + count(&thptr->nptr); 
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

void print(struct node* ptr)
{
	struct node* thptr = ptr;
	while(thptr != NULL)
	{
		printf("%d", thptr->data);
		thptr = thptr->nptr;
	}
}
