/*
Name : Archana R
Roll : MT2016021

Program to find the K smallest numbers, in a large unsorted array of size N.
Using Median approach.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void generate_numbers(int n);

int main(int argc, char const *argv[])
{
	
	int n;
	int k;
	printf("Enter the size n and the value of K \n");
	scanf("%d %d",&n,&k);
	generate_numbers(n);
	int size = 2*k;
	int a[size];
	int num;
	int i;
	FILE *fp = fopen("input_median.txt","r");
	for(i=0;i<size;i++)
	{
		fscanf(fp, "%d ", &num);
		a[i] = num;
	}
	find_rank(a,0,size-1,size/2);
	//print_array(a,size);
	int repeat = (n - 2*k)/k;	
	int j;
	for(j=0;j<repeat;j++)
	{
		for(i = k; i<size; i++)
		{
			fscanf(fp, "%d ", &num);
			a[i] = num;			
		}
		find_rank(a,0,size-1,size/2);
	}
	
	if(n%k != 0) // if K not multiple of N, fill the remaining numbers and find rank
	{
		for(i = k; i<k + n%k; i++)
		{
			fscanf(fp, "%d ", &num);
			a[i] = num;	
		}
		//find_rank(a,0,k + n%k -1,n%k);  // can find n%k rank
		//OR find rank of median itself, as the array size is 2K.s
		find_rank(a,0,size-1,size/2);
	}
	
	printf("K smallest numbers: \n");
	print_array(a,size/2);
	
	return 0;
}

int find_rank(int a[], int i, int j, int rank)
{
	
	if(i==j)
	{
		return a[i];
	}
	while(i<j)
	{
		int p_ind = rand()%(j-i+1) + i;
		int p = a[p_ind];
		int k = partition(a,i,j,p_ind);
		int ind;
			
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
	int pivot = a[p];
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
print_array(int a[], int size)
{
	int i;
	printf("Array :  ");
	for( i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

find_index(int a[], int pivot, int l, int r)
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
void generate_numbers(int n)
{
	srand(time(NULL));
	FILE *fp = fopen("input_median.txt","w");
	int mod = 1000;
	int i, element;
	for (i = 0; i < n; ++i)
	{
		element = rand()%mod + 1;
		//printf("%d ", element);
		fprintf(fp, "%d ", element);
	}
	//printf("\n");
	fclose(fp);
}