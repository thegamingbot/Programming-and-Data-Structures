#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* head1=NULL;
struct node* head2=NULL;
struct node* head3=NULL;
struct node* head4=NULL;
struct node* head5=NULL;

void print(struct node* root);
void insert(int x, struct node** ptr);
void sunion();
void search(int x);
void removeDuplicates(struct node *start);

int main()
{
	int a,n,m;
	int p,q;
	printf("Enter the no. of numbers for 1st set ");
	scanf("%d",&n);
	for(int i=0;i<n;i-=-1)
	{
		printf("Enter the %d number ",i);
		scanf("%d",&p);
		insert(p,&head1);
	}
	removeDuplicates(head1);
	printf("Enter the no. of numbers for 2nd set ");
	scanf("%d",&m);
	for(int i=0;i<m;i-=-1)
	{
		printf("Enter the %d number ",i);
		scanf("%d",&q);
		insert(q,&head2);
	}
	removeDuplicates(head2);
	sunion();
	printf("Enter the no. to check membership of S1\n");
	scanf("%d",&a);
	search(a);
}

void insert(int x,struct node** ptr)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	struct node* tp=*ptr;

	if(*ptr==NULL)
	*ptr=temp;

	else
	{
		while((tp->next)!=NULL)
		{
		tp=tp->next;
		}
	tp->next=temp;
	}
}

void sunion()
{
	struct node* tp1=head1;
	struct node* tp2=head2;
	int flag=0;
	while(tp1!=NULL)
	{
		flag=0;
		while(tp2!=NULL)
		{
			if(tp1->data!=tp2->data)
			tp2=tp2->next;
			else
			{
				flag=1;
				break;
			}
		}
		tp2=head2;
		if(flag==0)
		{
			insert(tp1->data,&head3);
			insert(tp1->data,&head5);
		}
		else
			insert(tp1->data,&head4);
			tp1=tp1->next;	
		}
	tp2=head2;
	while(tp2!=NULL)
	{
		insert(tp2->data,&head3);
		tp2=tp2->next;
	}
	printf("UNION of S1 and S2 ");
	print(head3);
	printf("\n");
	printf("INTERSCETION of S1 and S2- ");
	print(head4);
	printf("\n");
	printf("COMPLEMENT of S2 consedering S1 as union set- ");
	print(head5);
	printf("\n");
}

void print(struct node* root)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	tmp=root;
	while(tmp!=NULL)
	{
		printf("%d\t",tmp->data);
		tmp=tmp->next;
	}
}

void search(int x)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->next=head1;
	temp->data=x;
	int flag=0;
	while(temp->next!=NULL)
	{
		if(x==(temp->next)->data)
		{
			flag=1;
			break;
		}
		else
			temp=(temp->next);
	}
	if(flag==1)
		printf("it is member of S1");
	if(flag==0)
		printf("It is not the member of S1");
}

void removeDuplicates(struct node *start) 
{ 
    struct node *ptr1, *ptr2, *dup; 
    ptr1 = start;
    while (ptr1 != NULL && ptr1->next != NULL) 
    { 
        ptr2 = ptr1; 
        while (ptr2->next != NULL) 
        {
            if (ptr1->data == ptr2->next->data) 
            {
                dup = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                delete(dup); 
            } 
            else
                ptr2 = ptr2->next; 
        } 
        ptr1 = ptr1->next; 
    } 
} 
