/*
Name : Archana R
Roll : MT2016021

Given a rank, Program to find the corresponding element, in a large unsorted array of size N.
Using deterministic(good) pivot approach.

Assuming the range of numbers is m=100 (in generate_numbers funtion)
NOTE : comiple using -lm option to include the math library (for the ceil funtion)
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void print_array(int a[], int n);
void generate_numbers(int a[], int n);

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the size N\n");
	scanf("%d",&n);
	int arr[n];

	generate_numbers(arr,n);
	print_array(arr,n);

	// Random rank within the range
	int rank = rand() % n +1;
	printf("\nRANK : %d\n", rank);
	int res = find_rank(arr, 0, n-1, rank, n);
	printf("RESULT : %d\n", res);
	return 0;
}
int mycomp(const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );
}
int good_pivot(int a[], int start, int end)
{

	if(end-start < 4)
	{
		// sort them and pick 
		qsort(a+start,end-start+1, sizeof(int),mycomp);
		int p;
		//qsort(a,n,sizeof(int),mycomp);
		if(start-end == 1) // 2 elements
		{
			p = a[end];
		}
		else if(end-start == 2) // 3 elements
		{
			p = a[start+1];
		}
		else if(end-start == 3) // 4 elements
		{
			p = a[start+2];
		}
		else
		{
			p = a[start];
		}
		return p;
	}

	// sort 5 each
	int groups = ceil((end-start+1)/5.0);
	int s = start;
	int e = end;
	int inter = s+4; // each interval size
	int i,j;
	int x;
	// sort each groups
	for ( x = 0; x < groups; ++x)
	{		
		qsort(a+s, inter-s+1, sizeof(int), mycomp);
		s = inter + 1 ;
		inter = inter+5 > end ? end : inter+5; // choose whichever is smaller : end index or the next interval index
	}
	
	//take all medians in first n/5 elements; - indexes - 2,7,12,17 etc
	j = 2;
	for ( i = 0; i < groups-1; ++i)
	{
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		j += 5;
	}
	// if the last group has exactly 5 elements
	if(inter%5 + 1 == 5)
	{
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	// if the last group has < 5 elements, pick the median accordingly
	else if(inter%5 + 1 < 5)
	{
		//update j (the median index)
		int diff = inter%5 + 1; // the difference
		if(diff==4 || diff == 3) j = inter - 1;
		else if(diff == 2 || diff == 1) j = inter;
		// swap a[i] with a[j]
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;

	}

	return find_rank(a, start, start + (end-start +1)/5-1, (end-start+1)/10);
}

int find_rank(int a[], int i, int j, int rank)
{
	if(i==j)
	{
		return a[i];
	}
	while(i<j)
	{	
		int p = good_pivot(a,i,j);
		int k = partition(a,i,j,p);
		if(rank == j-k+1)
		{
			return p;
		}
		else if(rank < j-k+1)
		{
			// go right
			return find_rank(a,k+1,j,rank);
		}
		else
		{
			// left
			return find_rank(a,i,k-1,rank-(j-k+1));
		}
	}	
}


int partition(int a[], int l, int r, int p)
{
	int i = l;
	int j = r;
	int pivot = p;
	while(i <= j)
	{
		while(a[i] <= pivot)
		{
			i++;
		}
		while(a[j] > pivot)
		{
			j--;
		}
		if(i<j)
		{
			int temp;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			
		}
	}
	int ind = find_index(a,pivot,l,r);
	int temp = a[ind];
	a[ind] = a[j];
	a[j] = temp;
	return j;
}

int find_index(int a[], int pivot, int l, int r)
{
	int i;
	for(i=l;i<=r;i++)
	{
		if(a[i] == pivot)
		{
			break;
		}
	}
	return i;
}

void print_array(int a[], int n)
{
	int i;
	printf("\nArray: ");
	for ( i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void generate_numbers(int a[], int n)
{
	srand(time(NULL));
	int mod = 100;
	int i, element;
	for (i = 0; i < n; ++i)
	{
		element = rand()%mod + 1;
		a[i] = element;
	}
}