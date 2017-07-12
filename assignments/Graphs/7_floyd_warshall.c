/*
Name : Archana R
Roll : MT2016021

Program to find the All pair shortest path - Floyd Warshall
*/
#include <stdio.h>
#define INFINITE 999
int main(int argc, char const *argv[])
{
	int n ;
	printf("enter number of vertices\n");
	scanf("%d",&n);
	int a[n+1][n+1], w[n+1][n+1], d[n+1][n+1];
	int  path[n+1][n+1];

	create_matrix(n, a, w, d, path);
	floyd_warshall(n, d, path);
	print_result(n, d, path);
	return 0;
}

int print_result(int n, int d[][n+1], int path[][n+1])
{
	int i,j;
	printf("weight matrix:\n");
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}

	printf("PATH:\n");
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			printf("%d ", path[i][j]);
		}
		printf("\n");
	}
}

int print_array(int n, int a[][n+1])
{
	int i,j;
	for ( i = 0; i <= n; ++i)
	{
		for ( j = 0; j <= n; ++j)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

}
floyd_warshall(int n, int d[][n+1], int path[][n+1])
{
	int i,j,k;
	for (k = 1; k <= n; ++k)
	{
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= n; ++j)
			{
				if(d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					//path[i][j] = k;
					path[i][j] = path[k][j];
				}
				
			}

		}
	}
	
}
int create_matrix(int n, int a[][n+1], int w[][n+1], int d[][n+1], int path[][n+1])
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
	}
	for (i = 0; i <= n; ++i)
	{
		for (j = 0; j <= n; ++j)
		{

			d[i][j] = w[i][j];
			//printf(" i: %d, j :%d d : %d , w : %d\n",i,j,d[i][j],w[i][j]);
			if(a[i][j] == 1)
			{
				path[i][j] = i;
			}
			else
			{
				path[i][j] = 0;
			}
		}
	}
}

