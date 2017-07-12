/*
Name : Archana R
Roll : MT2016021

Radix sort.
NOTE : Compile using -lm option. Ton incluse math library for power function
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define DIGITS 3
int main(int argc, char const *argv[])
{

	srand(time(NULL));
	int n = SIZE;
	int d = DIGITS;
	int k = 10; // each digit ranges from 0 to 9 
	int a[n],b[n];
	int c[k];

	int i;
	// array a : random integers in  range
	for ( i = 0; i < n; ++i)
	{
		a[i] = rand()%1000; // 3 digit long
	}
	print_array(a,n);

	//initialise Count array to 0
	for ( i = 0; i < k; ++i)
	{
		c[i] = 0;
	}
	int ind,j;
	for(i=0; i < d; i++)
	{
		int x;
		for ( ind = 0; ind < k; ++ind)
		{
			c[ind] = 0;
		}
		for(j=0; j<n; j++)
		{
			x = (int) a[j]/pow(10,i);
			c[x%10]++;
		}

		//cumulative sum
		for ( ind = 1; ind < k; ++ind)
		{
			c[ind] = c[ind] + c[ind-1];
		}

		// fill array b : Sorted
		for ( ind = n-1; ind >= 0; ind--)
		{
			x = (int) a[ind]/pow(10,i);
			b[c[x%10]-1] = a[ind];
			c[x%10]--;
		}

		//copy b to a
		for ( ind = 0; ind < n; ++ind)
		{
			a[ind] = b[ind];
		}
	}
	printf("\nAfter sorting:\n");
	print_array(a,n);

	return 0;
}
print_array(int a[], int n)
{
	int i;
	printf("Array: ");
	for ( i = 0; i < n; ++i)
	{
		//a[i] = rand()%10;
		printf("%d ", a[i]);
	}
	printf("\n");
}