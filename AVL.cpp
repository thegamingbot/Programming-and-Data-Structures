#include<stdio.h>
#include<stdlib.h>

struct node 
{ 
    int key; 
    struct node *left;
	struct node *right;
	int height;
}; 
   
struct node *newNode(int item);
struct node* AVLinsert(struct node* node, int key);
int height(struct node* node);
int max(int a, int b);
int BF(struct node* node);
struct node* RR(struct node* x);
struct node* LR(struct node* x);  
void preorder(struct node *root); 
void preorder1(struct node *root);
   
int main() 
{
    struct node* root = NULL;
    root = AVLinsert(root, 10); 
    root = AVLinsert(root, 20); 
    root = AVLinsert(root, 30); 
    root = AVLinsert(root, 40); 
    root = AVLinsert(root, 50);
	preorder(root);
   
    return 0; 
}

struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = NULL;
	temp->right = NULL;
	temp->height = 0;
    return temp; 
}

struct node* AVLinsert(struct node* node, int key) 
{ 
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left  = AVLinsert(node->left, key);
    else if (key >= node->key)
        node->right = AVLinsert(node->right, key);
    node->height = 1 + max(height(node->left), height(node->right));
    
    int bal_factor = BF(node);
    
    if (bal_factor > 1 && key < node->left->key) 
    {
	    return RR(node);
	}
	else if (bal_factor < -1 && key > node->right->key) 
    {
		return LR(node);
    }
    else if (bal_factor > 1 && key > node->left->key) 
    { 
        node->left =  LR(node->left); 
        return RR(node); 
    }
    else if (bal_factor < -1 && key < node->right->key) 
    { 
        node->right = RR(node->right); 
        return LR(node); 
    }
    
    return node; 
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
    if (root != NULL) 
    { 
        printf("%d \t", root->key); 
        preorder(root->left); 
        preorder(root->right); 
    } 
}

void preorder1(struct node *root) 
{ 
    if (root != NULL) 
    { 
        printf("%d \t", root->height); 
        preorder1(root->left); 
        preorder1(root->right); 
    } 
}
