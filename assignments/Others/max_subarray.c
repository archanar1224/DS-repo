/*
Name : Archana R
Roll : MT2016021

Program to find the max subarray
Using 3 approaches.

*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int main(int argc, char const *argv[])
{
	// given array, find maxiumum sub array
	srand(time(NULL));
	int n = SIZE;
	int arr[n];
	int i;
	for ( i = 0; i < n; ++i)
	{
		arr[i] = rand()%19 + (-9); // to include negative numbers as well
		printf("%d ", arr[i]);
	}
	printf("\n");

	
	int res1 = max_subarr_n2(arr,n); // 1. computes the max subarray - normal method :max subarry atlea O(n^2)
	printf("\n1.O(n^2) result: %d\n", res1);

	int res2  = max_subarr(arr, 0, n-1); // 2. computes the max subarry using divide and conquer : O(nlogn)
	printf("2.Result from divide and conquer: %d\n", res2 );
	
	int res3 = max_subarr_const_space(arr,n); // 3. computes the max subarry using sum approach : O(n)
	printf("3.O(n) algo result: %d\n",res3);
	
	
	return 0;
}
int max_subarr(int a[], int l, int h)
{
	if(l==h)
	{
		return a[l];
	}
	else
	{
		int mid = (l+h)/2;
		int left_sum = max_subarr(a,l,mid);
		int right_sum = max_subarr(a,mid+1,h);
		int cross_sum = max_cross(a,l,mid,h);

		if(left_sum >= right_sum && left_sum >= cross_sum)
		{
			return left_sum;
		}
		else if(right_sum >= left_sum && right_sum >= cross_sum)
		{
			return right_sum;
		}
		else
		{
			return cross_sum;
		}
	}
}

int max_cross(int a[], int l, int mid, int h)
{
	int left_sum, right_sum;
	left_sum = a[mid];
	right_sum = a[mid+1];
	int left_ind, right_ind;
	int i,j;
	i = mid;
	j = mid+1;
	int sum=0;
	for(i=mid;i>=0;i--)
	{
		sum = sum + a[i];
		if(sum>left_sum)
		{
			left_sum = sum;
			left_ind = i;
		}
	}
	sum = 0;
	for(j=mid+1;j<=h;j++)
	{
		sum = sum + a[j];
		if(sum>right_sum)
		{
			right_sum = sum;
			right_ind = j;
		}
	}
	return left_sum + right_sum;
}
int max_subarr_n2(int a[], int n)
{
	int max = a[0];
	int i,j;
	int sum;
	for(i=0;i<n;i++)
	{
		sum = 0;
		for(j=i;j<n;j++)
		{
			sum = sum + a[j];
			if(sum>max)
			{
				max = sum;
			}
		}
	}
	return max;
}

int max_subarr_const_space(int a[], int n)
{
	int i = 0;
	int j;
	
	int sum = 0;
	i = 0;
	int maxj = 0;
	int max = a[0];
	for (j = 0; j < n; ++j)
	{
		sum = sum + a[j];
		if(sum > max)
		{
			max = sum;
			maxj = j;
		}	
		if(sum<0)
		{
			// update min index i 
			i = j + 1;
			sum = 0;
		}
	}
	return max;
}