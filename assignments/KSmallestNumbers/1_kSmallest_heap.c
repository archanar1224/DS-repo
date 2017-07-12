/*
Name : Archana R
Roll : MT2016021

Program to find the K smallest numbers, in a large unsorted array of size N.
Using Heap approach.

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
	int a[k];
	generate_numbers(n); // generate the numbers randomly and store in a file
	int i;
	FILE *fp = fopen("input_heaps.txt","r");
	int num ;
	int size;
	// form the max heap for the first K elements
	for (i = 0; i < k; ++i)
	{
		fscanf(fp, "%d ", &num);
		size = add_element(a, size, num);
	}

	// rest of n-k numbers
	for (i = k; i < n; ++i)
	{
		fscanf(fp, "%d ", &num);
		if(num < a[0])	// smaller than max
		{
			size = delete_max(a, size);
			size = add_element(a, size, num);

			/* OR can also replace the top element with the new number and do a top down heapify :
			a[0] = num;
			top_down_heapify(a, 0, size);
			*/
		}
	}
	printf("K smallest numbers: \n");
	print_heap(a, size);
	
	return 0;
}

int add_element(int a[], int n, int elememt) // max heap
{
	a[n] = elememt;
	bottom_up_heapify(a,n);
	n++;
	return n;
}

int delete_max(int a[], int n)
{
	// swap top and last element 
	int temp = a[0];
	a[0] = a[n-1];
	a[n-1] = temp;
	n--;
	top_down_heapify(a,0,n);
	
	return n;
}

bottom_up_heapify(int a[], int i) //  max heap
{
	while(i>0 && a[(i-1)/2] < a[i])
	{
		int temp = a[(i-1)/2];
		a[(i-1)/2] = a[i];
		a[i] = temp;

		i = (i-1)/2;
	}
}


top_down_heapify(int a[], int i, int n)
{
	while(2*i+1 < n)
	{
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int max;
		if(r<n && a[l]<a[r]) 
		{
			max = r;
		}
		else
		{
			max = l;
		}

		//compare max and parent
		if(a[i] < a[max])
		{
			int temp = a[i];
			a[i] = a[max];
			a[max] = temp;

			i = max;
		}
		else // already a heap
		{
			break;
		}
	}
}

void generate_numbers(int n)
{
	srand(time(NULL));
	FILE *fp = fopen("input_heaps.txt","w");
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
print_heap(int a[], int size)
{
	int i;
	for( i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
