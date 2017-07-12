/*
Name : Archana R
Roll : MT2016021

Program to find the maximum gap, i<j
O(n)
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int main(int argc, char const *argv[])
{
	// given array, find max (a[j] - a[i]) ; i<j
	srand(time(NULL));
	int n = 10;
	int arr[n];
	int i;
	for ( i = 0; i < n; ++i)
	{
		arr[i] = rand()%100;
		printf("%d ", arr[i]);
	}
	printf("\n");
	//int diff = max_n2(arr,n);
	int diff = max_n(arr,n);
	printf("Maximum gap: %d\n", diff);
	return 0;
}

int max_n2(int a[], int n)
{
	int i,j;
	int max = a[1] - a[0];
	for ( i = 1; i < n; ++i)
	{
		for( j = i+1; j < n; ++j)
		{
			if(a[j]-a[i] > max)
			{
				max = a[j]-a[i];
			}
		}
	}
	return max;
}

int max_n(int a[], int n)
{
	int i = 0;
	int j;
	int max = a[1] - a[0];
	for (j = 1; j < n; ++j)
	{
		if(a[j] - a[i] > max)
		{
			max = a[j] - a[i];
		}	
		if(a[j] < a[i])
		{
			// update min index i 
			i = j;
		}
	}
	return max;
}