/*
Name : Archana R
Roll : MT2016021
Knapsack, maximize profit with W size.
Example input:
4
2 12
1 10
3 21
2 15
*/
#include <stdio.h>
int construct_table(int kp, int w[], int v[], int n);
int main(int argc, char const *argv[])
{
	int n;
	printf("Enter number of items\n");
	scanf("%d",&n);
	int i;
	int weight[n+1], value[n+1];
	weight[0] = value[0]= 0;
	printf("Enter weight and vale of each item\n");
	for ( i = 1; i <= n; ++i)
	{
		scanf("%d %d",&weight[i],&value[i]);

	}
	int knapsack;
	printf("Enter knapsack size\n");
	scanf("%d",&knapsack);
	construct_table(knapsack, weight, value, n);
	
	return 0;
}

int construct_table(int kp, int w[], int v[], int n)
{
	int t[n+1][kp+1];
	int i=0;
	for(i=0;i<=n;i++)
	{
		t[i][0]=0;
	}
	for (i = 1; i <= kp; i++) 
	{
		t[0][i] = 0;
	}
	for (i = 1; i <= kp; ++i)
	{
		t[1][i] = w[1] <= i ? v[1] : 0;
	}

	int j;
	
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= kp; ++j)
		{
			//include ?
			int incl = j >= w[i] ? t[i-1][j-w[i]] + v[i] : 0;

			// exclude
			int excl = t[i-1][j];

			//take max
			t[i][j] = incl > excl ? incl : excl;

			//printf("inc : %d, exc : %d\n",incl,excl);
			
			
		}
	}
	printf("Table:\n");
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= kp; ++j)
		{
			printf("%d  ", t[i][j]);
		}
		printf("\n");
	}
	// table is done, now back track to get which coins

  	printf("Included items :\n");
  	reconstruct(kp, t, n, kp, w);
}
reconstruct(int size, int t[][size+1], int i, int kp, int w[])
{
	if(i==0)
	{
		return;
	}
	if(t[i][kp] > t[i-1][kp])
	{
		printf("Item %d\n",i);
		reconstruct(size, t, i-1, kp -w[i],w);
	}
	else
	{
		reconstruct(size, t, i-1,kp,w);
	}
}