#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{ 
    char word[30];
	char meaning[200]; 
    struct node *left;
	struct node *right;
	int height;
}; 
   
struct node *newNode(char* word, char* meaning);
struct node* AVLinsert(struct node* node, char* word, char* meaning);
int height(struct node* node);
int max(int a, int b);
int BF(struct node* node);
struct node* RR(struct node* x);
struct node* LR(struct node* x);
struct node* search(struct node* root, char* word);  
void preorder(struct node *root);
   
int main() 
{
    struct node* root = NULL;
    int n;
    char word[30], meaning[200];
    printf("Enter the number of words to be added in the dictionary: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i -=- 1)
    {
    	printf("Enter the word: ");
    	scanf("%s", &word);
    	printf("Enter the meaning of '%s': ", word);
    	scanf("%s", &meaning);
    	root = AVLinsert(root, word, meaning);
	}
    preorder(root);
    printf("Enter the word you wish to search: ");
    scanf("%s", &word);
    struct node* temp;
	temp = search(root, word);
    printf("%s", temp->meaning);
   
    return 0; 
}

struct node *newNode(char* word, char* meaning) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    strcpy(temp->word, word);
    strcpy(temp->meaning, meaning);
    temp->left = NULL;
	temp->right = NULL;
	temp->height = 0;
    return temp; 
}

struct node* AVLinsert(struct node* node, char* word, char* meaning) 
{ 
    if (node == NULL)
        return newNode(word, meaning);
    if (strcmp(word, node->word) < 0)
        node->left  = AVLinsert(node->left, word, meaning);
    else if (strcmp(word, node->word) >= 0)
        node->right = AVLinsert(node->right, word, meaning);
    node->height = 1 + max(height(node->left), height(node->right));
    
    int bal_factor = BF(node);
    
    if (bal_factor > 1 && strcmp(word, node->left->word) < 0) 
    {
	    return RR(node);
	}
	else if (bal_factor < -1 && strcmp(word, node->right->word) >= 0) 
    {
		return LR(node);
    }
    else if (bal_factor > 1 && strcmp(word, node->left->word) >= 0) 
    { 
        node->left =  LR(node->left); 
        return RR(node); 
    }
    else if (bal_factor < -1 && strcmp(word, node->right->word) < 0) 
    { 
        node->right = RR(node->right); 
        return LR(node); 
    }
    
    return node; 
}

struct node* search(struct node* root, char* word)
{
	struct node* troot = root;
    if (troot == NULL || strcmp(troot->word, word) == 0)
    	return troot;
	else if (strcmp(troot->word, word) < 0)
    	return search(troot->right, word);
	else
    	return search(troot->left, word);
}

int height(struct node* node)  
{  
    if (node == NULL)  
        return 0;
    else
    {
        int lh = height(node->left);  
        int rh = height(node->right);
        if (lh > rh)  
            return(lh + 1);  
        else 
			return(rh + 1);  
    }  
}

int max(int a, int b)
{
	if(a < b)
		return b;
	else 
		return a;
}

int BF(struct node* node)
{
	if(node == NULL)
		return 0;
	return height(node->left) - height(node->right);
}

struct node* RR(struct node* x) 
{ 
    struct node *y = x->left; 
    struct node *z = y->right; 
    
    y->right = x; 
    x->left = z; 

    x->height = 1 + max(height(x->left), height(x->right)); 
    y->height = 1 + max(height(y->left), height(y->right)); 

    return y; 
} 

struct node* LR(struct node* x) 
{
    struct node *y = x->right; 
    struct node *z = y->left; 
    
    y->left = x; 
    x->right = z; 

    x->height = 1 + max(height(x->left), height(x->right)); 
    y->height = 1 + max(height(y->left), height(y->right)); 

    return y; 
} 

void preorder(struct node *root) 
{ 
	struct node* troot = root;
    if (root != NULL) 
    { 
        printf("%s\t%s\n",troot->word, troot->meaning); 
        preorder(troot->left); 
        preorder(troot->right); 
    } 
}
