/*
Name : Archana R
Roll : MT2016021

Given 2 arrays, A : array of numbers, B : array of ranks (distinct) and sorted.
Find the elements in A for each rank in B.
Using the partition approach, left of B : search in Right of A and viceversa.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void print_array(int a[], int n);
void repeating_rank(int a[], int i, int j, int b[], int x, int y, int sub);
int n;
int main(int argc, char const *argv[])
{
	int m;
	printf("Enter the size of Array A and B \n");
	scanf("%d %d",&n,&m);
	int a[n]; int b[m];
	srand(time(NULL));
	int i;
	for ( i = 0; i < n; ++i)
	{
		a[i] = rand()%100 + 1;
	}
	for ( i = 0; i < m; ++i)
	{
		b[i] = (i+1);  // or any other distinct number within the range of n 
	}
	printf("Numbers array:\n");
	print_array(a,n);
	printf("Ranks array:\n");
	print_array(b,m);

	repeating_rank(a,0,n-1,b,0,m-1,0);
	print_array(a,n);
	return 0;
}

void repeating_rank(int a[], int i, int j, int b[], int x, int y, int sub)
{
	int mid_b;
	int part=0;
	if(x<=y)
	{
		mid_b = (y + x)/2;
		int res = find_rank(a,i,j,b[mid_b]-sub);
		printf("Rank: %d Number: %d \n",b[mid_b], res);
		int part = find_index(a,res,i,j);

		//right of A, left of B
		repeating_rank(a, part+1, j, b, x, mid_b-1, 0);

		//left of A, right of B
		repeating_rank(a, i, part-1, b, mid_b+1, y, n-part);
	}
}

void print_array(int a[], int n)
{
	int i;
	for ( i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int find_rank(int a[], int i, int j, int rank)
{
	if(i==j)
	{
		return a[i];
	}
	while(i<j)
	{
		int p_ind = rand()%(j-i+1) + i;
		int p = a[p_ind];
		int k = partition(a,i,j,p_ind);
		int ind;		
		if(rank == j-k+1)
		{
			return p;
		}
		else if(rank < j-k+1)
		{
			// go right		
			return find_rank(a,k+1,j,rank);
		}
		else
		{
			// left
			return find_rank(a,i,k-1,rank-(j-k+1));
		}
	}	
}

int partition(int a[], int l, int r, int p)
{
	int i = l;
	int j = r;
	int pivot = a[p];
	while(i <= j)
	{
		while(a[i] <= pivot)
		{
			i++;
		}
		while(a[j] > pivot)
		{
			j--;
		}
		if(i<j)
		{
			int temp;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			
		}
	}
	int ind = find_index(a,pivot,l,r);
	int temp = a[ind];
	a[ind] = a[j];
	a[j] = temp;
	return j;
}

int find_index(int a[], int pivot, int l, int r)
{
	int i;
	for(i=l;i<=r;i++)
	{
		if(a[i] == pivot)
		{
			break;
		}
	}
	return i;
}