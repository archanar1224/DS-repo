/*
Name : Archana R
Roll : MT2016021

Given a rank, Program to find the corresponding element, in a large unsorted array of size N.
Using random pivot approach.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void generate_numbers(int a[], int n);
void print_array(int a[], int n);

int main(int argc, char const *argv[])
{
	
	int n;
	printf("Enter the size N\n");
	scanf("%d",&n);
	int arr[n];
	int i;
	int x;
	generate_numbers(arr,n);
	print_array(arr,n);

	
	int rank = rand() % n +1; // choose a Random rank within the array size range
	printf("RANK : %d\n", rank);
	int res = find_rank(arr, 0, n-1, rank);
	printf("RESULT : %d\n", res);	
	return 0;
}

int find_rank(int a[], int i, int j, int rank)
{
	
	if(i==j)
	{
		return a[i];
	}
	while(i<j)
	{
		int p_ind = rand()%(j-i+1) + i;  // choose a random index within the bounds
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
void generate_numbers(int a[], int n)
{
	srand(time(NULL));
	int mod = 1000;
	int i, element;
	for (i = 0; i < n; ++i)
	{
		element = rand()%mod + 1;
		a[i] = element;
	}
}
void print_array(int a[], int size)
{
	int i;
	for( i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}