/*
Name : Archana R
Roll : MT2016021

Program to find the max absolute gap , i!=j
Using 3 approaches: 1. O(n^2) 2.Sort :  O(nlogn) ;  3.O(n)
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
int main(int argc, char const *argv[])
{
	// given array, find max abs(a[i] - a[j]) ; i!=j
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
	//int diff = max_n2(arr,n);

	//int diff = max_sort(arr,n);

	int diff = max_n(arr,n);

	printf("DIFF : %d\n", diff);
	return 0;
}

int max_n2(int a[], int n)
{
	int i,j;
	int max = a[0] - a[1]; // or 0
	for ( i = 0; i < n; ++i)
	{
		for( j = i+1; j < n; ++j)
		{
			if(abs(a[i]-a[j]) > max)
			{
				max = abs(a[i]-a[j]);
			}
		}
	}
	return max;
}

int mycomp(const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );
}

int max_sort(int a[], int n)
{
	qsort(a, n, sizeof(int), mycomp);
	printf("AFTER sorting\n");
	int i;
	for ( i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	int max = abs(a[0] - a[n-1]);

	return max;
}
int max_n(int a[], int n)
{
	int i;
	int min = a[0];
	int max = a[0];
	for (i = 1; i < n; ++i)
	{
		if(a[i] > max)
		{
			max = a[i];
		}	
		if(a[i] < min)
		{
			min = a[i];
		}
	}

	printf("max : %d min : %d\n", max,min);
	return max-min;
}