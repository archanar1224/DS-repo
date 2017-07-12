/*
Name : Archana R
Roll : MT2016021

Reb-Black tree implementation (Insertion, Deletion)
Functions file
*/
#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct node* create_node(int data, char color)
{
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = data;
	new_node->color = color;
	new_node->left = nil;
	new_node->right = nil;
	new_node->parent = nil;

	return new_node;
}
void traverse_tree(struct node* root)
{
	printf("Inoder traversal : \n");
	inorder(root);
	printf("\nPreOrder traversal : \n");
	preorder(root);
	printf("\n");
}
struct node* rbt_delete(struct node *root, int key)
{
	struct node *temp = search(root, key);
	if(temp == NULL)
	{
		printf(" %d Does not exist", key);
	}
	else
	{
		root = delete(root, temp);
	}
	return root;
}
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == nil )
    	return NULL;
    if(root->data == key)
       return root;
   
    // Key is greater than root's key
    if (root->data < key)
       return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}
struct node* insert(struct node *root, struct node *z)
{
	struct node *y = nil;
	struct node *x = root;
	while(x!= nil)
	{
		y = x;
		if(z->data < x->data)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	z->parent = y;
	if(y == nil)
	{
		root = z;
	}
	else if(z->data < y->data)
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}

	z->left = nil;
	z->right = nil;
	z->color = 'R';
	root = fixup(root, z);
	return root;
}	

struct node* fixup(struct node *root, struct node *x)
{
	struct node *par = nil;
	struct node *gp = nil;

	while( (x != root) && (x->color == 'R') && (x->parent->color == 'R'))
	{
		par = x->parent;
		gp = x->parent->parent;
	
		// parent is left child
		if(par == gp->left)
		{
			struct node *uncle = gp->right;
			//case 1 : uncle is red , recoloring
			if(uncle != nil && uncle->color == 'R')
			{
				par->color = 'B';
				uncle->color = 'B';
				gp->color = 'R';
				x = gp;
			}

			else 
			{
				if (x == par->right) // zig zag case 2
				{
					//2 rotations first left rotate and then right
					x = par;
					root = left_rotate(root, x);
				}	
				// case 3
				// zig zig only right rotate
				par->color = 'B';
				gp->color = 'R';
				root = right_rotate(root, gp);
			}

		}
		else // parent is right child
		{
	
			struct node *uncle = gp->left;

			// uncle is red
			if((uncle != nil) && (uncle->color == 'R'))
			{
				par->color = 'B';
				uncle->color = 'B';
				gp->color = 'R';
				x = gp;
			}
			else
			{
				if (x == par->left) // zig zag case 2
				{
					//2 rotations first right rotate and then left
					x = par;
					root = right_rotate(root, x);
				}	
				// case 3
				// zig zig only left rotate
				par->color = 'B';
				gp->color = 'R';
				root = left_rotate(root, gp);
			}
		}
	}
	root->color = 'B';
	return root;
}


struct node* left_rotate(struct node *root, struct node *x)
{
	struct node *y = x->right;
	x->right = y->left;

	if(y->left != nil)	
	{
		y->left->parent = x;
	}
	y->parent = x->parent;

	if(x->parent == nil)
	{
		root = y;
	}
	else if (x == x->parent->left)
	{
		x->parent->left = y;	
	}
	else
	{
		x->parent->right = y;
	}

	y->left = x;
	x->parent = y;
	printf("left_rotate, %d\n",root->data);
	return root;
}

struct node* right_rotate(struct node *root, struct node *x)
{
	struct node *y = x->left;
	x->left = y->right;

	if(y->right != nil)	
	{
		y->right->parent = x;
	}
	y->parent = x->parent;

	if(x->parent == nil)
	{
		root = y;
	}
	else if (x == x->parent->right)
	{
		x->parent->right = y;	
	}
	else
	{
		x->parent->left = y;
	}

	y->right = x;
	x->parent = y;
	return root;
}


void inorder(struct node *root)
{
	if (root == nil)
	{
    	return;
	}
 
	inorder(root->left);
 
	printf("%d:%c ", root->data, root->color);  
 
	inorder(root->right);
}

void preorder(struct node *root)
{
	if (root == nil)
	{
    	return;
	}
 
 	printf("%d:%c ", root->data, root->color); 
	preorder(root->left);
	preorder(root->right);
}

struct node* transplant(struct node* root, struct node* u, struct node *v)
{
	if(u->parent == nil)
	{
		root = v;
	}
	else if(u == u->parent->left)
	{	
		u->parent->left = v;
	}
	else
	{
		u->parent->right = v;
	}	
	v->parent = u->parent;
	return root;

}

struct node* delete(struct node *root, struct node *z)
{
	struct node *y = z;
	struct node *x;
	char y_color = y->color;

	// single right child
	if(z->left == nil)
	{
		x = z->right;
		root = transplant(root, z, z->right);
	}
	// single left child
	else if(z->right == nil)
	{
		x = z->left;
		root = transplant(root, z, z->left);
	}
	// 2 children
	else
	{
		y = get_minimum(z->right);
		y_color = y->color;
		x = y->right;

		if (y->parent == z)
		{
			x->parent = y;
		}
		else
		{
			root = transplant(root, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}

		root = transplant(root, z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}

	if(y_color == 'B')
	{
		root = delete_fixup(root, x);
	}
	return root;
}

struct node* delete_fixup(struct node *root, struct node *x)
{
	while(x != root && x->color == 'B')
	{
		if(x == x->parent->left)
		{
			struct node *w = x->parent->right;

			if(w->color == 'R')
			{
				w->color = 'B';
				x->parent->color = 'R';
				root = left_rotate(root, x->parent);
				w = x->parent->right;
			}
			if(w->left->color == 'B' && w->right->color == 'B')
			{
				w->color = 'R';
				x = x->parent;
			}
			else if(w->right->color == 'B')
			{
				w->left->color = 'B';
				w->color = 'R';
				root = right_rotate(root, w);
				w = x->parent->right;

			}

			w->color = x->parent->color;
			x->parent->color = 'B';
			w->right->color = 'B';
			left_rotate(root, x->parent);
			x = root;
		}
		else
		{
			struct node *w = x->parent->left;

			if(w->color == 'R')
			{
				w->color = 'B';
				x->parent->color = 'R';
				root = right_rotate(root, x->parent);
				w = x->parent->left;
			}
			if(w->right->color == 'B' && w->left->color == 'B')
			{
				w->color = 'R';
				x = x->parent;
			}
			else if(w->left->color == 'B')
			{
				w->right->color = 'B';
				w->color = 'R';
				root = left_rotate(root, w);
				w = x->parent->left;
			}

			w->color = x->parent->color;
			x->parent->color = 'B';
			w->left->color = 'B';
			right_rotate(root, x->parent);
			x = root;
		}
	}
	x->color = 'B';
}

struct node* get_minimum(struct node *x)
{
	struct node *temp = x;
	while(temp->left != nil)
	{
		temp = temp->left;
	}
	return temp;
}