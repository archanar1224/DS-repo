/*
Name : Archana R
Roll : MT2016021

Program to find the DFS traversal of a graph

*/
#include <stdio.h>
#define SIZE 20

void dfs(int n, int a[][n+1], int status[], int path[], int disc[], int finish[], int time);
int dfs_visit(int u, int n, int a[][n+1], int status[], int path[], int disc[], int finish[], int time);
int main(int argc, char const *argv[])
{
	int n ;
	printf("enter number of vertices\n");
	scanf("%d",&n);
	int a[n+1][n+1];
	int time = 0;
	int status[n+1], disc[n+1], path[n+1];
	int finish[n+1];
	create_matrix(n, a, status, disc, finish, path);
	print_array(n,a);
	printf("DFS:\n");
	dfs(n,a,status,path,disc,finish,time);
	
	print_path(n,a,path,disc,finish);
	return 0;
}

int print_path(int n, int a[][n+1], int path[], int disc[], int finish[])
{
	int i;
	for (i = 1; i <= n; ++i)
	{
		printf("vertex : %d,  %d/%d \n",i,disc[i],finish[i]);
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
int create_matrix(int n, int a[][n+1],int status[], int disc[], int finish[], int path[])
{
	int i=0,j=0;
	int c =0;
	for ( i = 0; i <= n; ++i)
	{
		for (j = 0; j <= n; ++j)
		{
			a[i][j] = 0;
		}
		
	}	
	for ( i = 0; i <= n; ++i)
	{
		status[i] = 0;
		path[i] = 0;
		disc[i] = 0;
		finish[i] = 0;
	}
	while(1)
	{
		printf("Enter source and destination (0 to stop)\n");
		scanf("%d %d",&i,&j);
		
		if(i==0)break;
		a[i][j] = 1;
		//a[j][i] = 1;
	}
}

void dfs(int n, int a[][n+1], int status[], int path[], int disc[], int finish[], int time)
{
	int i;
	//int time = 0;
	for ( i = 1; i <= n; ++i)
	{
		if(status[i]==0)
		{
			time = dfs_visit(i, n, a, status, path, disc, finish, time);
		}
	}
	printf("\n");
}
int dfs_visit(int u, int n, int a[][n+1], int status[], int path[], int disc[], int finish[], int time)
{
	int v;
	time++;
	status[u]=1;
	disc[u] = time;
	printf("%d ",u);
	for( v=1;v<=n;v++)
	{
		if(a[u][v]==1 && status[v]==0 )
		{
			path[v] = u;
			time = dfs_visit(v,n,a,status,path,disc,finish,time);
		}
	}	
	time = time + 1;
	finish[u] = time;
}
