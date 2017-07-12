/*
Name : Archana R
Roll : MT2016021
Matrix multiplication
*/
#include <stdio.h>
#define INFINITE 999999
int construct_table(int n, int p[]);
int main(int argc, char const *argv[])
{
	int n;
	printf("Enter number\n");
	scanf("%d",&n);
	int i;
	int p[n+1];
	printf("Enter pi's\n");
	for ( i = 0; i <= n; ++i)
	{
		scanf("%d",&p[i]);

	}
	construct_table(n, p);
	
	return 0;
}
int print_array(int n, int a[][n+1])
{
	int i,j;
	for ( i = 1; i <= n; ++i)
	{
		for ( j = 1; j <= n; ++j)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

}

int print_paranthesis(int n, int s[][n+1], int i, int j)
{
	if(i==j)
	{
		printf("A%d",i);
	}
	else
	{
		printf("(");
		print_paranthesis(n, s, i, s[i][j]);
		print_paranthesis(n, s, s[i][j] + 1, j);
		printf(")");
	}


}
int construct_table(int n, int p[])
{
	int m[n+1][n+1];
	int s[n+1][n+1];
	int i=0;
	
	int j,l,k,q;
	
	for (i = 0; i <= n; ++i)
	{
		for (j = 0; j <= n; ++j)
		{
			s[i][j] = 0;
			m[i][j] = 0;
		}
	}
	for(i=0;i<=n;i++)
	{
		m[i][i]=0;
	}
	
	for (l = 2; l <=n; ++l)
	{
		for (i = 1; i <= n-l+1; ++i)
		{
			j = i + l - 1;
			m[i][j] = INFINITE;
			for (k = i; k <= j-1; ++k)
			{
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
				
				
			}
		}
	}	

	printf("Table:\n");
	print_array(n,m);
	printf("Result:\n");
	print_paranthesis(n,s,1,n);
	printf("\n");
}