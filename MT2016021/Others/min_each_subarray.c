/*
Name : Archana R
Roll : MT2016021

Program to find the minimum value in each subarray of length k. 
In time O(n), using 2 traversals, one from left to right and then one from right to left, storing the minimums of subarrays, seen so far.


*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define k_SIZE 4

void print_array(int a[], int n);
int main(int argc, char const *argv[])
{
	// given array, find maxiumum sub array
	srand(time(NULL));
	int n = SIZE;
	int arr[n];
	int i;
	printf("Array : \n");
	for ( i = 0; i < n; ++i)
	{
		arr[i] = rand()%19 + (-9); // to include negative numbers as well
		printf("%d ", arr[i]);
	}
	printf("\n");
	int k = k_SIZE;
	int l[n],r[n];
	int result[n-k+1];

	for(i=0;i<n;i++)
	{
		if(i%k==0)
		{
			l[i] = arr[i];
		}
		else
		{
			l[i] = l[i-1]>arr[i]? l[i-1] : arr[i]; // max of l[i-1] or current element
		}
	}

	for(i=n-1;i>=0;i--)
	{
		if(i==n-1)
		{
			r[i] = arr[i];
		}
		else if(i%k == (k-1))
		{
			r[i] =  arr[i];
		}
		else
		{
			r[i] = r[i+1]>arr[i]? r[i+1] : arr[i]; 
		}
	}

	for ( i = 0; i < n-k+1; ++i)
	{
		result[i] = r[i] > l[i+k-1] ? r[i] : l[i+k-1];
	}
	printf("\nMinimums of subarrays of length %d:\n", k);
	print_array(result,n-k+1);
	return 0;
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