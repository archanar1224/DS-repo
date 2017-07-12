/*
Name : Archana R
Roll : MT2016021
Subset sum
t[i][j] => first i items, sum exactly j

*/
#include <stdio.h>
int construct_table(int s, int a[], int n);
int main(int argc, char const *argv[])
{
	int n;
	printf("Enter size\n");
	scanf("%d",&n);
	int i;
	int a[n+1];
	printf("Enter values\n");
	for ( i = 1; i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	int sum ;
	printf("Enter sum\n");
	scanf("%d",&sum);
	construct_table(sum, a, n);
	return 0;
}

int construct_table(int sum, int a[], int n)
{
	int t[n+1][sum+1];
	int i=0;
	for(i=0;i<=n;i++)
	{
		t[i][0]=0;
	}
	for (i = 1; i <= sum; i++) 
	{
		t[0][i] = 0;
	}
	for (i = 1; i <= sum; ++i)
	{
		t[1][i] = i==a[1] ? 1 : 0;
	}

	int j;
	
	for (i = 2; i <= n; ++i)
	{
		for (j = 1; j <= sum; ++j)
		{
			if(j == a[i])
			{
				t[i][j] = 1;
			}
			else
			{
				t[i][j] = (t[i-1][j-a[i]] == 1 || t[i-1][j] == 1) ? 1 : 0;
			}
			
		}
	}

	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= sum; ++j)
		{
			printf("%d  ", t[i][j]);
		}
		printf("\n");
	}
	
	if(t[n][sum] == 1)
	{
		printf("Sum of %d is possible\n", sum);
		printf("Set:\n");
		reconstruct(sum,t,n,sum,a);
		printf("\n");
	}
	else
	{
		printf("Sum not possible\n");
	}
	
}
reconstruct(int size, int t[][size+1], int i, int sum, int a[])
{
	if(sum==0)
	{
		return;
	}
	if(t[i][sum] > t[i-1][sum])
	{
		printf(" %d ",a[i]);
		reconstruct(size, t, i-1, sum - a[i], a);
	}
	else
	{
		reconstruct(size, t, i-1, sum, a);
	}
}