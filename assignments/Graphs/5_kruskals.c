/*
Name : Archana R
Roll : MT2016021
Kruskals - Minimum spanning tree
*/
#include <stdio.h>
#include <stdlib.h>

struct edge
{
	int weight;
	int u,v;
	struct edge *next;
};
struct vertex
{
	int colour;
	int vert;
	struct vertex *next;
};
struct edge* insert(struct edge *e, struct edge *head);
void swap(struct edge *a, struct edge *b);

struct edge* bubbleSort(struct edge *head);
void create_matrix(int n);

int main(int argc, char const *argv[])
{	
	int n;
	printf("Enter number of vertices\n");
	scanf("%d",&n);
	
	create_matrix(n);
	return 0;
}
print_list(int n, struct edge *head)
{
	int i;
	struct edge *temp;
	/*for ( i = 1; i <=n; ++i)
	{
		temp = adj[i];
		while(temp!= NULL)
		{
			printf(" %d (%d,%d) : %d\n", i, temp->u, temp->v, temp->weight);
			temp = temp->next;
		}
	}*/
	printf("HEAD:\n");
	struct edge *temp2 = head;
	while(temp2 != NULL)
	{
		printf("(%d,%d) : %d\n", temp2->u, temp2->v, temp2->weight);
		temp2 = temp2->next;
	}
}
void create_matrix(int n )
{
	int i=0,j=0;
	int weight;
	int c =0;
	struct edge *head = NULL;
	int a[n+1][n+1], w[n+1][n+1];
	int colour_list[n+1];
	int count[n+1];
	struct vertex *vertex_list[n+1];
	colour_list[0] = 0;
	for ( i = 0; i <=n ; ++i)
	{
		struct vertex *temp = (struct vertex*) malloc(sizeof(struct vertex));
		temp->vert = i;
		temp->colour = i;
		temp->next = NULL;
		vertex_list[i] = temp;
		colour_list[i] = i;
		count[i] = 1;
	}
	count[0] = 0;
	while(1)
	{
		printf("Enter source and destination and weight (0 to stop)\n");
		scanf("%d %d %d",&i,&j,&weight);
		
		if(i==0)break;
		struct edge *e = (struct edge*) malloc(sizeof(struct edge));
		e->weight = weight;
		e->u = i;
		e->v = j;
		e->next = NULL;
		head = insert(e, head);
		
	}
	print_list(n,head);
	head = bubbleSort(head);
	printf("After sort\n");
	print_list(n,head);


	/*printf("COLOURS:\n");
	for ( i = 1; i <= n; ++i)
	{
		printf("i : %d , colour : %d ", i, colour_list[i]);
	}
	printf("\nCOUNTs:\n");
	for ( i = 1; i <= n; ++i)
	{
		printf(" i : %d, count : %d ", i, count[i]);
	}
	printf("\n");*/
	int iterations = 0;
	printf("MIN SPANNING TREE\n");
	struct edge *ptr = head;
	while(iterations<n-1)
	{
		int u = ptr->u;
		int v = ptr->v;
		if(colour_list[u] != colour_list[v])
		{

			printf("EDGE : (%d, %d) , weight : %d\n",u,v,ptr->weight);
			if(count[colour_list[u]] <= count[colour_list[v]])
			{
				// change colours of u's and attach u to v's start
				struct vertex *uu = vertex_list[u];
				struct vertex *prev = NULL;
				while(uu != NULL)
				{
					uu->colour = vertex_list[v]->colour;
					colour_list[uu->vert] = vertex_list[v]->colour;
					prev = uu;
					uu = uu->next;
				}
				prev->next = vertex_list[v];
				vertex_list[v] = vertex_list[u];
				count[v] = count[v] + count[u];
				count[u] = 0;
				//printf("YOYO %d\n", iterations);
				
			}

			else
			{
				// change colours of v's and attach v to u's start
				struct vertex *vv = vertex_list[v];
				struct vertex *prev = NULL;
				while(vv != NULL)
				{
					vv->colour = vertex_list[u]->colour;
					colour_list[vv->vert] = vertex_list[u]->colour;
					prev = vv;
					vv = vv->next;
				}
				prev->next = vertex_list[u];
				vertex_list[u] = vertex_list[v];
				count[u] = count[u] + count[v];
				count[v] = 0;
				//printf("YOYO WW%d\n", iterations);
			}
			iterations++;
		}
		ptr = ptr->next;
	}
	/*printf("\nCOLOURS:\n");
	for ( i = 1; i <= n; ++i)
	{
		printf("i : %d , colour : %d ", i, colour_list[i]);
	}
	printf("\nCOUNTs:\n");
	for ( i = 1; i <= n; ++i)
	{
		printf(" i : %d, count : %d ", i, count[i]);
	}
	printf("\n");*/
}

struct edge* bubbleSort(struct edge *head)
{
    int swapped, i;
    struct edge *ptr1;
    struct edge *lptr = NULL;
 
    /* Checking for empty list */
    if (head == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = head;
 
        while (ptr1->next != lptr)
        {
            if (ptr1->weight > ptr1->next->weight)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
    return head;
}

 
/* function to swap data of two nodes a and b*/
void swap(struct edge *a, struct edge *b)
{
    int temp_weight = a->weight;
    a->weight = b->weight;
    b->weight = temp_weight;

    int temp_u = a->u;
    a->u = b->u;
    b->u = temp_u;

    int temp_v = a->v;
    a->v = b->v;
    b->v = temp_v;
}

struct edge* insert(struct edge *e, struct edge *head)
{
	if(head==NULL)
	{
		head = e;
	}
	else
	{
		e->next = head;
		head = e;
	}
	return head;
}