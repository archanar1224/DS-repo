/*
Name : Archana R
Roll : MT2016021

Program to find the Single source shortest path - Bellman Ford

*/

#include <stdio.h>
#define INFINITE 999
int main(int argc, char const *argv[])
{
	int n ;
	printf("enter number of vertices\n");
	scanf("%d",&n);
	int a[n+1][n+1], w[n+1][n+1], d[n+1];
	int path[n+1];
	int i,j;
	create_matrix(n, a, w);
	printf("Adj matrix :\n");
	for ( i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
		
	}	
	printf("Weight matrix :\n");
	for ( i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			printf("%d ", w[i][j]);
		}
		printf("\n");
		
	}	
	printf("Enter source\n");
	int source;
	scanf("%d",&source);
	bellman_ford(n, a, w, d, path, source);
	printf("Distances :\n");
	print_result(n, d, path);
	return 0;
}

int print_result(int n, int d[], int path[])
{
	int i,j;
	for (i = 1; i <= n; ++i)
	{
		printf("%d ", d[i]);
	}
	printf("\n");
	printf("PATH:\n");
	for (i = 1; i <= n; ++i)
	{
		printf("%d ", path[i]);
	}
	printf("\n");

}

int print_array(int n, int a[])
{
	int i,j;
	for ( i = 1; i <= n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	
}
bellman_ford(int n, int a[][n+1], int w[][n+1], int d[], int path[], int source)
{
	int i,j,k;
	for (i = 1; i <= n; ++i)
	{
			if(a[source][i] == 1)
			{
				
				d[i] = w[source][i];
				//printf("inside i : %d , w: %d\n", i,d[i]);
				path[i] = source;
			}
			else
			{
				d[i] = INFINITE;
				path[i] = 0;
			}
	}
	//printf("Before d:\n");
	//print_array(n,d);
	
	//printf("Path before:\n");
	//print_array(n,path);
	for (k = 1; k <= n; ++k)
	{
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= n; ++j)
			{
				if(a[i][j] == 1)
				{
					if(d[i] + w[i][j] < d[j])
					{
						d[j] = d[i] + w[i][j];
						path[j] = i;

					}
				}
			}
		}
	}
}
int create_matrix(int n, int a[][n+1], int w[][n+1])
{
	int i=0,j=0;
	int weight;
	int c =0;
	for ( i = 0; i <= n; ++i)
	{
		for (j = 0; j <= n; ++j)
		{
			a[i][j] = 0;
			w[i][j] = INFINITE;
			if(i==j)
			{
				w[i][j] = 0;
			}
		}
		
	}	
	
	while(1)
	{
		printf("Enter source and destination and weight (0 to stop)\n");
		scanf("%d %d %d",&i,&j,&weight);
		
		if(i==0)break;
		w[i][j] = weight;
		a[i][j] = 1;
		//a[j][i] = 1;
	}
	
}

