/*
Name : Archana R
Roll : MT2016021

Perfect hash implementation (Insertion, Deletion)
Header file
*/
#define SIZE 1000000
#ifndef NODE_H
#define NODE_H
struct node
{
	long long int data;
	struct node *next;
};
struct primary
{
	int count;
	struct node *list;

};
struct hash
{
	int a2, b2, p2;
	int ni2;
	long long int *arr_ptr;
};
#endif
extern int a,b;
extern long long int p;

long int get_prime(long int n);
void print_pairs(struct hash *myhash, int m, int limit);
long int find_sum(struct primary *pri, int m);
struct primary* primary_hash( int n, int m, const char *filename);
struct hash* secondary_hash(struct primary *pri, int m, int n, const char *filename);
void search(struct hash *myhash, int m, long long int num);
int isDuplicate(long long int num, struct node *list);
void print_pri(struct primary *pri, int m);
long int find_sum(struct primary *pri, int m);
int isPrime(long int n);
