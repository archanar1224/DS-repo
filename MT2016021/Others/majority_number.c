/*
Name : Archana R
Roll : MT2016021

Program to find the majority number (if exists)
Using 2 approaches: 1.Sort :  O(nlogn) ;  2.Bucket : O(n)

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
int main(int argc, char const *argv[])
{
	// given array, find if there is a majority number, i.e if a number repeats atleast n/3 + 1 times
	srand(time(NULL));
	int n = SIZE;
	int arr[n];
	int i;
	for ( i = 0; i < n; ++i)
	{
		arr[i] = rand()%10;
		printf("%d ", arr[i]);
	}
	printf("\n");
	majority_sort(arr,n); // 1. using sorting method
	majority_bucket(arr,n); // 2. using bucket method
	return 0;	
}

int mycomp(const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );
}
int majority_sort(int a[], int n)
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


	int count = 1;
	int max = 1;
	i = 0;
	int j=0;
	while(i<n)
	{
		while(a[i] == a[i+1])
		{
			i++; 
			count++;
		}
		
		if(count > max)
		{
			max = count;
			j = i;
		}
		count = 1;
		i++;
	}
	printf("1.From Sorting:\n");
	if(max>3)
	{
		printf("Majority exists, Number: %d, Count : %d\n", a[j], max);
	}
	else
	{
		printf("No majority number\n");
	}
	//printf("max : %d a[j] : %d\n", max, a[j]);
	return a[j];
}

int majority_bucket(int a[], int n)
{
	int b1,b2; //buckets;
	int c1,c2; //counts
	c1=0;c2=0;
	int flag = 0;
	int i;
	int maj=0;
	int count = 0;
	for (i = 0; i < n; ++i)
	{		
		if(c1>0 && b1==a[i])
		{
			c1++;
		}
		else if(c2>0 && b2==a[i])
		{
			c2++;
		}

		else if(c1==0)
		{
			c1++;
			b1 = a[i];
		}
		else if(c2==0)
		{
			c2++;
			b2 = a[i]; 
		}
		else // drop
		{
			c1--;
			c2--;
		}
	}
	if(c1>0 && c2>0)
	{
		c1 = 0; c2 = 0;
		for (i = 0; i < n; ++i)
		{
			if(a[i]==b1) c1++;
			else if(a[i]==b2) c2++;
		}
		//printf("b1 : %d c1 : %d ;; b2 : %d c2 : %d\n", b1,c1,b2,c2);
		if(c1>=n/3+1 || c2>=n/3+1)
		{
			count = c1>c2?  c1 : c2;
			maj = c1>c2 ? b1:b2;
			flag = 1;
		} 
	}
	else if(c1>0)
	{	
		c1 = 0;
		for (i = 0; i < n; ++i)
		{
			if(a[i]==b1) c1++;
		}
		//printf("b1 : %d , c1 : %d\n", b1,c1);
		if(c1>=n/3+1)
		{
			maj = b1;
			count = c1;
			flag = 1;
		}
	}
	else if(c2>0)
	{
		c2 = 0;
		for (i = 0; i < n; ++i)
		{
			if(a[i]==b2) c2++;
		}
		//printf("b1 : %d , c1 : %d\n", b2,c2);
		if(c2>=n/3+1)
		{
			maj = b2;
			count = c2;
			flag = 1;
		}

	}
	printf("2.From Bucket :\n");
	if(flag)
	{
		printf("Majority exists. Number : %d, Count : %d\n",maj,count);
	}
	else
	{
		printf("No majority\n");
	}

}