/*
Name : Archana R
Roll : MT2016021

Program to find the minimum length subarray that contains all the elements from 1 to K, atleast once. 
In time O(n)
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20
#define K_size 4

void print_array(int a[], int n);
void min_length_subarray(int a[], int n, int k);
int main(int argc, char const *argv[])
{

	srand(time(NULL));
	int n = SIZE;
	int a[n];
	int i;
	printf("Array : \n");
	for ( i = 0; i < n; ++i)
	{
		a[i] = rand()%10 + 1 ;
		printf("%d ", a[i]);
	}
	printf("\n");
	int k = K_size;	
	min_length_subarray(a,n,k);
	return 0;
}

void min_length_subarray(int a[], int n, int k)
{

	int count[k];
	int i;
	for (i = 0; i < k; ++i)
	{
		count[i] = 0;
	}
	int total_count=0;
	
	int j;
	int min_length = n; // initialising it to length of array
	int min_i = 0; int min_j = n-1;
	i=0;
	for(j=0;j<n;j++)
	{
		if(a[j] <= k)
		{
			if(count[a[j]-1]==0)
			{
				total_count++;
			}
			count[a[j]-1]++;
		}

		if (total_count==k)
		{
			while(a[i] > k || count[a[i]-1]>1)
			{
				count[a[i]-1]--;
				i++;
			}
			if(j-i < min_length)
			{
				min_length = j-i;
				min_i = i;
				min_j = j;
			}
		}
	}
	printf("Min_length indices:\ni: %d, j: %d\n",min_i,min_j);
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