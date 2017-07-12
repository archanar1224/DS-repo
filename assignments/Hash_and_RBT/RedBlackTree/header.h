/*
Name : Archana R
Roll : MT2016021

Reb-Black tree implementation (Insertion, Deletion)
Header file
*/
#ifndef NODE_H
#define NODE_H
struct node
{
	int data;
	char color; // 'R' or 'B'
	struct node *left, *right, *parent;

};
#endif
struct node* create_node(int data, char color);
struct node* insert(struct node *root, struct node *x);
struct node* fixup(struct node *root, struct node *x);

struct node* left_rotate(struct node *root, struct node *x);
struct node* right_rotate(struct node *root, struct node *x);

void inorder(struct node *root);
void preorder(struct node *root);
void traverse_tree(struct node *root);
struct node* search(struct node* root, int key);
struct node* transplant(struct node* root, struct node* u, struct node *v);
struct node* rbt_delete(struct node *root, int key);
struct node* delete(struct node *root, struct node *z);
struct node* delete_fixup(struct node *root, struct node *x);
struct node* get_minimum(struct node *x);

struct node* nil;