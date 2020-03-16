#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char word[30];
	char meaning[200];
	struct node* left;
	struct node* right;
	int height;
};

int height(struct node* node);
struct node* insert(struct node* root, char* word, char* meaning);
struct node* search(struct node* root, char* word);
struct node* birth(char* word, char* meaning);
struct node* right(struct node* x);
struct node* left(struct node* x);
int max(int a, int b);
void pre(struct node* node);

int main()
{
	struct node* root = NULL;
	int n;
	char word[30], meaning[200];
	printf("Enter the number of words in the dictionary:  ");
	scanf("%d", &n);
	for(int i = 0; i < n; i -=- 1)
	{
		printf("Enter the word:  ");
		scanf("%s", &word);
		printf("Enter the meaning of '%s':  ", word);
		scanf("%s", &meaning);
		root = insert(root, word, meaning);
	}
	printf("The pre order of the AVL tree is: \n");
	pre(root);
	printf("Enter the word to be searched:  ");
	scanf("%s", &word);
	struct node* temp = search(root, word);
	printf("The meaning of the searched word '%s' is %s\n", temp->word, temp->meaning);
}

struct node* birth(char* word, char* meaning)
{
	struct node* temp = (struct node* ) malloc(sizeof(struct node));
	strcpy(temp->word, word);
	strcpy(temp->meaning, meaning);
	temp->left = NULL;
	temp->right = NULL;
	temp->height = 0;
	return temp; 
}

struct node* insert(struct node* root, char* word, char* meaning)
{
	if(root == NULL)
		return birth(word, meaning);
	if(strcmp(root->word, word) > 0)
		root->left = insert(root->left, word, meaning);
	else
		root->right = insert(root->right, word, meaning);
	
	root->height = 1 + max(height(root->left), height(root->right));
	
	int bf;
	bf = height(root->left) - height(root->right);
	
	if(bf > 1 && strcmp(root->left->word, word) >= 0)
		return right(root);
	else if(bf < -1 && strcmp(root->right->word, word) < 0)
		return left(root);
	else if(bf > 1 && strcmp(root->left->word, word) < 0)
	{
		root->left = left(root->left);
		return right(root);
	}
	else if(bf < -1 && strcmp(root->right->word, word) >= 0)
	{
		root->right = right(root->right);
		return left(root);
	}
	
	return root;
}

struct node* search(struct node* root, char* word)
{
	if(root == NULL || strcmp(root->word, word) == 0)
		return root;
	else if(strcmp(root->word, word) > 0)
		return search(root->left, word);
	else
		return search(root->right, word);
}

int max(int a, int b)
{
	if(a < b)
		return b;
	else 
		return a;
}

int height(struct node* node)
{
	if(node != NULL)
	{
		int lh = height(node->left);
		int rh = height(node->right);
		
		return 1 + max(lh, rh);
	}
}

struct node* right(struct node* x)
{
	struct node* y = x->left;
	struct node* z = y->right;
	
	y->right = x;
	x->left = z;
	
	x->height = 1 + max(height(x->left), height(x->right));
	y->height = 1 + max(height(y->left), height(y->right));
	
	return y;
}

struct node* left(struct node* x)
{
	struct node* y = x->right;
	struct node* z = y->left;
	
	y->left = x;
	x->right = z;
	
	x->height = 1 + max(height(x->left), height(x->right));
	y->height = 1 + max(height(y->left), height(y->right));
	
	return y;
}

void pre(struct node* node)
{
	if(node != NULL)
	{
		printf("%s  %s\n", node->word, node->meaning);
		pre(node->left);
		pre(node->right);
	}
}
