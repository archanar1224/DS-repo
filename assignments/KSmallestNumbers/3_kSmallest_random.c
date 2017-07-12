/*
Name : Archana R
Roll : MT2016021

Program to find the K smallest numbers, in a large unsorted array of size N.
Using Random pivot and partition approach.
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
	find_kSmallest(a,k,size,n);

	return 0;
}

find_kSmallest(int a[], int k, int size, int n)
{

	int i; int num;
	FILE *fp = fopen("input_random.txt","r");
	for(i=0;i<size;i++)
	{
		fscanf(fp, "%d ", &num);
		a[i] = num;
	}
	int yet_to_read = n - size;
	i = 0;
	int j = size -1;
	while(yet_to_read > 0)
	{
		int p_ind = rand()%(j-i+1) + i;
		int p = a[p_ind];
		int part_ind = partition(a,i,j,p_ind);
		if(part_ind >= k)  // if partition falls on RHS, replace with new elements
		{
			int ind;
			int read = size - part_ind;
			if(yet_to_read < read)
			{
				read = yet_to_read;
			}
			for(ind = part_ind; ind < part_ind + read; ind++)
			{
				fscanf(fp, "%d ", &num);
				a[ind] = num;
				yet_to_read--;
			}
		}
	}
	// In the end, find median, and the first K elements is the result
	find_rank(a,0,size-1,k);
	print_array(a,k);
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
	FILE *fp = fopen("input_random.txt","w");
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