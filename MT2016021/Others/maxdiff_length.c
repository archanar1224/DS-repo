/*
Name : Archana R
Roll : MT2016021

Program to find the maximum gap, j > i + l ; alteast length l gap
O(n)
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define L 2
int main(int argc, char const *argv[])
{
	// given array, find max (a[j] - a[i]) ; j > i + l
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
	int l = L;
	printf("L : %d\n", l);
	int diff = max_n(arr,n,l);

	printf("DIFF : %d\n", diff);
	return 0;
}
int max_n(int a[], int n, int l)
{
	int i = 0;
	int j;
	int max = a[l+1] - a[0];
	for (j = l+1; j < n; ++j)
	{
		if(a[j] - a[i] > max)
		{
			max = a[j] - a[i];
		}	
		if(a[j-l] < a[i])
		{
			// update min index i 
			i = j-l;
		}
	}
	return max;
}