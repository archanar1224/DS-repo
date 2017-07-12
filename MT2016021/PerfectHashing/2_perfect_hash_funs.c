/*
Name : Archana R
Roll : MT2016021

Perfect hash implementation (Insertion, Deletion)
Functions file
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

struct primary* primary_hash(int n, int m, const char *filename)
{
	FILE *fp = fopen(filename,"r");
	if(fp == NULL)
	{
		printf("Error in opening file.. exiting\n");
		exit(1);
	}
	struct primary *pri = (struct primary*) malloc(sizeof(struct primary) * m);
	if(pri == NULL)
	{
		printf("Heap overflow.. exiting");
	}
	a = rand() % 100 + 1;
	b = rand() % 100 + 1;
	//printf("a : %d , b : %d\n", a,b);
	int i;
	for(i = 0; i < m; i++)
	{
		pri[i].count = 0;
		pri[i].list = NULL;
	}
	for (i = 0; i < n; ++i)
	{
		long long int temp;
		fscanf(fp,"%lld\n",&temp);
		int h = ( (a * temp + b ) % p ) % m;
	
		struct node *new_node = (struct node *) malloc(sizeof(struct node));
		if(new_node == NULL)
		{
			printf("Heap overflow.. exiting");
			exit(1);
		}
		new_node->data = temp;
		new_node->next = NULL;
	
		if(pri[h].count == 0)
		{			
			pri[h].list = new_node;
		}
		else
		{
			int flag = isDuplicate(new_node->data,pri[h].list);
			if(flag==1)
			{
				printf("Duplicate : %lld ignoring\n", new_node->data);
				free(new_node);
				continue;
			}
			struct node *old_head = pri[h].list;
			pri[h].list = new_node;
			pri[h].list->next = old_head;
		}
		pri[h].count = pri[h].count + 1;

	}
	long int sum = find_sum(pri,m);
	//printf("Sum from pri : %ld\n", sum);
	fclose(fp);
	return pri;
}

struct hash* secondary_hash(struct primary *pri, int m, int n, const char *filename)
{
	struct primary *mypri = pri;
	struct hash *myhash = (struct hash*) malloc(sizeof(struct hash) * m);
	if(myhash == NULL)
	{
		printf("Heap overflow.. exiting");
		exit(1);
	}
	int i;
	FILE *fp = fopen(filename,"r");
	if(fp == NULL)
	{
		printf("Error in opening file.. exiting\n");
		exit(1);
	}
	for (i = 0; i < m; ++i)
	{
		myhash[i].ni2 = 0;
		if(mypri[i].count > 0)
		{
			long int temp_ni2 = mypri[i].count * mypri[i].count;
			myhash[i].arr_ptr = (long long int *) malloc(sizeof(long long int) * temp_ni2);
			if(myhash[i].arr_ptr == NULL)
			{
				printf("Heap overflow.. exiting");
				exit(1);
			}
			int j;
			for (j = 0; j < temp_ni2; ++j)
			{
				myhash[i].arr_ptr[j] = 0;
			}
		}
	}
	for (i = 0; i < m; ++i)
	{
		long long int x;
		if(mypri[i].count > 0)
		{
			long int temp_ni2 = mypri[i].count * mypri[i].count;
			myhash[i].ni2 = temp_ni2;
			
			long int p2 = get_prime(temp_ni2);
			
			int res = foo(myhash,pri,m,n,p2,i,temp_ni2);
			while(res == 1)
			{
				p2 = get_prime(p2);
				res = foo(myhash,pri,m,n,p2,i,temp_ni2);
			}
		}
		
	}
	fclose(fp);
	return myhash;
}

void print_pairs(struct hash *myhash, int m, int limit)
{
	// | x - y | <= 10 (No pairs are present for <=10, Hence provide a larger difference limit of 10^5 or 10^6 atleast)
	printf("PAIRS with difference <= %d\n", limit);
	
	int i;
	int count = 0;
	for (i = 0; i < m; ++i)
	{
		int len = myhash[i].ni2;
		if(len > 0)
		{
			int j,k;
			for(j = 0; j < len; j++)
			{
				if(myhash[i].arr_ptr[j] == 0 ) // ignore
				{
					continue;
				}
				for (k = j+1; k < len; ++k)
				{
					if (myhash[i].arr_ptr[k] == 0) // ignore, empty cell
					{
						continue;
					}
					long long int diff = abs(myhash[i].arr_ptr[j] - myhash[i].arr_ptr[k]); 
					if(diff<=limit)
					{
						printf("PAIR : %lld , %lld \n", myhash[i].arr_ptr[j],myhash[i].arr_ptr[k] );
						count++;
					}

				}
			}
		}
	}
	printf("COUNT : %d\n", count);
	
}

int foo(struct hash *myhash, struct primary *pri, int m, int n, long int p2, int i, long int temp_ni2)
{
	int a2 = rand() % 100 + 1;
	int b2 = rand() % 100 + 1;
	int j;
	for (j = 0; j < temp_ni2; ++j)
	{
		myhash[i].arr_ptr[j] = 0;
	}
	struct node *temp_list = pri[i].list;
	while(temp_list !=NULL)
	{
		long long int x = temp_list->data;
		long int h2 = ( (a2 * x + b2 ) % p2 ) % temp_ni2;
		if(myhash[i].arr_ptr[h2] > 0 )
		{
			return 1; //error , collision
		}
		myhash[i].arr_ptr[h2] = x;
		temp_list = temp_list->next;
	}
	myhash[i].a2 = a2;
	myhash[i].b2 = b2;
	myhash[i].p2 = p2;
	return 0; 
}

void search(struct hash *myhash, int m, long long int num)
{
	int h = ( (a * num + b ) % p ) % m;
	//printf("h : %d\n", h);
	int a2 = myhash[h].a2;
	int b2 = myhash[h].b2;
	int p2 = myhash[h].p2;
	int ni2 = myhash[h].ni2;
	if(ni2 == 0)
	{
		printf("Not found : %lld\n", num);
	}
	else
	{
		long int h2 = ( (a2 * num + b2 ) % p2 ) % ni2;
		if(myhash[h].arr_ptr[h2] == num)
		{
			printf("FOUND : %lld\n", num);
		}
		else
		{
			printf("Not found : %lld\n", num);
		}
	}
	
}

int isDuplicate(long long int num, struct node *list)
{
	struct node *temp = list;
	while(temp!=NULL)
	{
		if(temp->data == num)
		{
			//duplicate 
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}
void print_pri(struct primary *pri, int m)
{
	struct primary *temp = pri;
	int i;
	for (i = 0; i < m; ++i)
	{
		if(temp[i].count>0)
		printf("i : %d, count : %d\n", i,temp[i].count);
		int temp_count = temp[i].count;
		struct node *temp_list = temp[i].list;
		while(temp_list !=NULL)
		{
			printf("val : %lld\n", temp_list->data);
			temp_list = temp_list->next;
		}
	}
}

long int find_sum(struct primary *pri, int m)
{
	struct primary *temp = pri;
	int i;
	long int sum = 0;
	for (i = 0; i < m; ++i)
	{
		long int sq = temp[i].count * temp[i].count;
		sum = sum + sq;
	}
	//printf("Sum : %ld\n", sum);
	return sum;
}

long int get_prime(long int n)
{
	long int p = n + 1;
	if(p%2==0)
	{
		p = p + 1;
	}
	while(isPrime(p) == 1)
	{
		p = p + 2;
	}
	return p;
}
int isPrime(long int n)
{
	long int i;
	int flag = 0;
	if((n%2==0)) 
	{
		flag = 1;
		return flag;
	}
	for(i=3; i<=n/2; i=i+2)
    {
        // condition for nonprime number
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
    return flag;
}