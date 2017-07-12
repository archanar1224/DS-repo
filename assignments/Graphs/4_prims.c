/*
Name : Archana R
Roll : MT2016021
Prims - Min spanning tree
*/
#include <stdio.h>


int heap_size = 0;
void add_element(int a[], int elememt);
int delete_min(int a[]);
void prims(int s, int n, int a[][n+1], int w[][n+1], int status[], int path[], int pri[]);
int main(int argc, char const *argv[])
{
	int n ;
	printf("enter number of vertices\n");
	scanf("%d",&n);
	int a[n+1][n+1], w[n+1][n+1];
	int status[n+1], pri[n+1], path[n+1];

	create_matrix(n, a, w, status, pri, path);
	print_array(n,w);

	int source = 1;
	prims(source,n,a,w,status,path,pri);
	print_result(n,w,path,pri);

	return 0;
}

int print_result(int n, int a[][n+1], int path[], int pri[])
{
	int i;
	for (i = 1; i <= n; ++i)
	{
		printf(" to vertex : %d,  cost : %d \n",i,pri[i]);
	}

	for (i = 2; i <= n; ++i)
	{
		{
			printf(" (%d,%d) ", path[i],i);
		}
	}

	printf("\n");
}

print_path(int v, int path[])
{

	if(path[v] !=0)
	{
		printf("(%d,%d) ",path[v],v);
		print_path(path[v], path);
	}
}

void prims(int s, int n, int a[][n+1], int w[][n+1], int status[], int path[], int pri[])
{
	int u,v;
	int heap[n+1];
	pri[s] = 0;
	add_element(heap,s);
	int i;
	/*for ( i = 1; i <= n; ++i)
	{
		add_element(heap,i);
	}*/
	//status[s] = 1;
	path[s] = 0;
	while(heap_size>0)
	{
		u = delete_min(heap);
		status[u] = 1;
		for(v=1;v<=n;v++)
		{
		//	printf("\n u : %d , v: %d, st : %d, a[u][v]: %d , size %d\n", u,v,status[v],a[u][v], heap_size);
			if(a[u][v]==1 && status[v]==0 && pri[v] > w[u][v])
			{
				pri[v] = w[u][v];
				path[v] = u;
				add_element(heap,v);
				printf("v :  %d, u : %d a: %d\n", v,u,a[u][v]);
			}
		}
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
int create_matrix(int n, int a[][n+1], int w[][n+1], int status[], int pri[], int path[])
{
	int i=0,j=0;
	int weight;
	int c =0;
	for ( i = 0; i <= n; ++i)
	{
		for (j = 0; j <= n; ++j)
		{
			a[i][j] = 0;
			w[i][j] = 999;
		}
		
	}	
	for ( i = 0; i <= n; ++i)
	{
		status[i] = 0;
		path[i] = 0;
		pri[i] = 999;
	}
	while(1)
	{
		printf("Enter source and destination and weight\n");
		scanf("%d %d %d",&i,&j,&weight);
		
		if(i==0)break;
		//printf("yo\n");
		w[i][j] = weight;
		w[j][i] = weight;
		a[i][j] = 1;
		a[j][i] = 1;
	}
}


void add_element(int a[], int elememt)
{
	a[heap_size] = elememt;
	bottom_up_heapify(a,heap_size);
	heap_size++;
	//return n;
}

int delete_min(int a[])
{
	// swap top and last element 
	int temp = a[0];
	a[0] = a[heap_size-1];
	a[heap_size-1] = temp;
	heap_size--;
	top_down_heapify(a,0,heap_size);
	
	return temp;
}

bottom_up_heapify(int a[], int i) //  min heap
{
	while(i>0 && a[(i-1)/2] > a[i])
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
		int min;
		if(r<n && a[l]>a[r]) 
		{
			min = r;
		}
		else
		{
			min = l;
		}

		//compare min and parent
		if(a[i] > a[min])
		{
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;

			i = min;
		}
		else // already a heap
		{
			break;
		}
	}
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

decrease_key(int a[], int i, int x)
{
	a[i] = x;
	bottom_up_heapify(a, i);

}

increase_key(int a[], int i, int x, int n)
{
	a[i] = x;
	top_down_heapify(a, i, n);
}

update_key(int a[], int i, int x, int n)
{
	if(a[i] > x)
	{
		decrease_key(a, i, x);
	}
	else
	{
		increase_key(a, i , x, n);
	}
}