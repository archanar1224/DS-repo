/*
Name : Archana R
Roll : MT2016021

Program to find the BFS traversal of a graph

*/
#include <stdio.h>
#define SIZE 20

struct queue{
	int f;
	int r;
	int q[SIZE];
};
void bfs(int s, int n, int a[][n], int status[], int path[], int disc[]);
int main(int argc, char const *argv[])
{
	int n ;
	printf("enter number of vertices\n");
	scanf("%d",&n);
	int a[n+1][n+1];
	int status[n+1], disc[n+1], path[n+1];
	create_matrix(n, a, status, disc, path);
	print_array(n,a);
	printf("BFS\n");
	bfs(1,n,a,status,path,disc);
	printf("\n");
	return 0;
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
int create_matrix(int n, int a[][n+1],int status[], int disc[], int path[])
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
	}
	while(1)
	{
		printf("Enter source and destination (0 to stop)\n");
		scanf("%d %d",&i,&j);
		
		if(i==0)break;
		//printf("yo\n");
		a[i][j] = 1;
		a[j][i] = 1;
	}
}

int empty(struct queue *m)
{
	if(m->f==-1)
		return 1;
	return 0;

}

void enqueue(struct queue *m,int x)
{
	m->r++;
	m->q[m->r]=x;
	if((m->r)==0)m->f=0;
}

int dequeue(struct queue *m)
{
	int x=m->q[m->f];
	if(m->f==m->r)
		m->f=m->r=-1;
	else
		m->f++;
		return x;
}

void bfs(int s, int n, int a[][n+1], int status[], int path[], int disc[])
{

	int v,u;
	struct queue p;
	p.r = p.f = -1;

	status[s]=1;
	disc[s] = 0;
	path[s] = 0;
	enqueue(&p,s);
	printf("%d ",s);
	
	while(!empty(&p))
	{
		u=dequeue(&p);
		for(v=1;v<=n;v++)
		{
			//printf(" u : %d , v: %d, st : %d, a[u][v]: %d \n", u,v,status[v],a[u][v]);
			if(a[u][v]==1 && status[v]==0)
			{
				status[v]=1;
				path[v] = u;
				disc[v] = disc[u] + 1;
				enqueue(&p,v);
				printf("%d ",v);
			}
		}

	}
}
