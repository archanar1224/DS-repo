/*
Name : Archana R
Roll : MT2016021

Given X, Program to find a[i[] + a[j] = x (if exists)
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
int main(int argc, char const *argv[])
{
	//given array a, find i,j such that a[i]+a[j] = x
	srand(time(NULL));
	int n = SIZE;
	int arr[n];
	int i;
	for ( i = 0; i < n; ++i)
	{
		arr[i] = rand()%100;
		printf("%d ", arr[i]);
	}
	printf("\n");
	// Choose random X 
	int x = rand()%100;
	printf("X : %d\n", x);
	int res = find_ij_sort(arr,n,x);  
	if (res==0)
	{
		printf("No i j exists\n");
	}
	
	return 0;
}


int mycomp(const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );
}
int find_ij_sort(int a[], int n, int x) //nlogn + n = nlogn
{
	//sort
	int i;
	qsort(a,n,sizeof(int),mycomp);
	printf("AFTER sorting\n");
	for ( i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	//assume sorted

	int l = 0; 
	int r = n-1;
	while(l<=r)
	{
		if(a[l] + a[r] == x)
		{
			printf("Found:\n");
			printf("Indices i:%d j:%d\n",l,r);
			printf("Numbers : %d, %d \n", a[l],a[r]);
			return 1;
		}
		else if(a[l] + a[r] < x)
		{
			l++;
		}
		else
		{
			r--;
		}
	}
	return 0;
}

find_ij_n2(int a[], int n, int x) //n^2
{
	int i,j;

	for(i=0;i<n;i++)
	{
		for (j = i+1; j < n; ++j)
		{
			if(a[i]+a[j] == x)
			{
				printf("a[i] a[j] %d %d\n", a[i],a[j]);
				return 1;
			}
		}
	}
	return 0;
}