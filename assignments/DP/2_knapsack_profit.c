/*
Name : Archana R
Roll : MT2016021
Knapsack , min size reqd to make atleast P profit
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
	int profit;
	printf("Enter profit\n");
	scanf("%d",&profit);
	construct_table(profit, weight, value, n);
	
	return 0;
}

int construct_table(int profit, int w[], int v[], int n)
{
	int t[n+1][profit+1];
	int i=0;
	for(i=0;i<=n;i++)
	{
		t[i][0]=0;
	}
	for (i = 1; i <= profit; i++) 
	{
		t[0][i] = 0;
	}
	for (i = 1; i <= profit; ++i)
	{
		t[1][i] = v[1] >= i ? w[1] : 999;
	}

	int j;
	
	for (i = 2; i <= n; ++i)
	{
		for (j = 1; j <= profit; ++j)
		{
			//include ?
			int incl = j >= v[i] ? t[i-1][j-v[i]] + w[i] : 999;

			// exclude
			int excl = t[i-1][j];

			//take min
			t[i][j] = incl < excl ? incl : excl;

			//printf("inc : %d, exc : %d\n",incl,excl);
			
			
		}
	}
	printf("Table:\n");
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= profit; ++j)
		{
			printf("%d  ", t[i][j]);
		}
		printf("\n");
	}
	
}