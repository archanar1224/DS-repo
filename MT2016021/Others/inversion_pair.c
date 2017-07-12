/*
Name : Archana R
Roll : MT2016021

Program to find the number of inversion pairs
Using 2 approaches: 1.Brute force : O(n^2) ;  2. Divide and conquer : O(nlogn)
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5
int main(int argc, char const *argv[])
{
	// given array, find # of inversion pairs , i.e a[i] > a[j] , increment count
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
	
	int res = ip_n2(arr,n);
	printf("Number of inversion pairs through :\n");
	printf("1. Brute force : %d\n", res);

	int res2 = merge(arr,0,n-1);
	printf("2. Divide n conquer : %d\n", res2);
	
	return 0;
}

int ip_n2(int a[], int n)
{
	int i,j;
	int count=0;
	for ( i = 0; i < n; ++i)
	{
		for ( j = i+1; j < n; ++j)
		{
			if(a[i] > a[j])
			{
				count++;
			}
		}
	}
	return count;
}

int merge(int a[], int l, int r)
{
	static int c = 0;
	if(l<r)
	{
		int k = (l+r)/2;
		merge(a,l,k);
		merge(a,k+1,r);
		c += ip_merge(a,l,r,k);
	}
	return c;
}

int ip_merge(int a[], int l, int r, int k)
{
	int i = l;
	int j = k+1;
	int count = 0;
	int b[r-l+1];
	int x=0;
	while(i<=k && j<=r)
	{
		if(a[i]<=a[j])
		{
			b[x++] = a[i];
			i++;

		}
		else
		{
			b[x++] = a[j];
			count += k - i + 1;
			j++;
		}

	}
	while(i <= k)    
    {
    	b[x++] = a[i++];
    }

	while(j <= r)   
    {
    	b[x++] = a[j++];
   	}

   	i = l;
   	x = 0;
   	while(i<=r)
   	{
   		a[i++] = b[x++];
   	}
	return count;
}