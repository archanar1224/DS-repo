/*
Name : Archana R
Roll : MT2016021

Count sort
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define RANGE 6 // 0 to 5
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int n,k;
	n = SIZE;
	k = RANGE;
	int a[n],b[n];
	int c[k];

	int i;
	// array a : random integers in k range
	for ( i = 0; i < n; ++i)
	{
		a[i] = rand()%k;
	}
	print_array(a,n);
	
	//initialise Count array to 0
	for ( i = 0; i < k; ++i)
	{
		c[i] = 0;
	}
	
	// fill array C
	for ( i = 0; i < n; ++i)
	{
		c[a[i]]++;
	}
	//cumulative sum
	for ( i = 1; i < k; ++i)
	{
		c[i] = c[i] + c[i-1];
	}
	// fill array b : Sorted
	for ( i = n-1; i >= 0; i--)
	{
		b[c[a[i]]-1] = a[i];
		c[a[i]]--;
	}
	printf("After sorting :\n");
	print_array(b,n);
	return 0;
}


print_array(int a[], int n)
{
	int i;
	printf("\nArray: ");
	for ( i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}