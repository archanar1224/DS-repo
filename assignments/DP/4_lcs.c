/*
Name : Archana R
Roll : MT2016021
Longest common subsequence
x[0..m] and y[0..n]
*/
#include <stdio.h>
int construct_table(char x[], char y[], int m, int n, int b[][n+1]);
int main(int argc, char const *argv[])
{
	int m,n;
	printf("Enter lengths\n");
	scanf("%d %d",&m, &n);
	int i;
	char x[m+1], y[n+1];
	int b[m+1][n+1];
	printf("Enter x and y\n");
	scanf("%s",&x[1]);
	scanf("%s",&y[1]);
	x[0] = '0';
	y[0] = '0';
	construct_table(x, y, m, n, b);
	printf("LCS:\n");
	print_lcs(n, b, x, m, n);
	printf("\n");
	return 0;
}

int check_present(char x, char y[], int n)
{
	int i;
	for ( i = 0; i <= n; ++i)
	{
		if(x==y[i])
		{
			return 1;
		}
	}
	return 0;
}
print_lcs(int n, int b[][n+1], char x[], int i, int j)
{
	if(i == 0 || j == 0)
	{
		return;
	}
	if(b[i][j] == 3) // up left
	{
		print_lcs(n,b,x,i-1,j-1);
		printf("%c",x[i]);
	}
	else if(b[i][j] == 1) //up
	{
		print_lcs(n,b,x,i-1,j);
	}
	else
	{
		print_lcs(n,b,x,i,j-1);
	}
}
int construct_table(char x[], char y[], int m, int n, int b[][n+1])
{
	int t[m+1][n+1];
	
	int i=0;
	int j;
	for(i=0;i<=m;i++)
	{
		for (j = 0; j <= n; ++j)
		{
			b[i][j] = 0;
		}	
	}
	
	for (i = 0; i <= n; ++i)
	{
		t[0][i] = 0;
	}
	for (i = 0; i <= m; ++i)
	{
		t[i][0] = 0;
	}
	
	for (i = 1; i <= m; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if(x[i]==y[j])			
			{
				t[i][j] = 1 + t[i-1][j-1];
				b[i][j] = 3; // up left

			}
			else
			{
				if(t[i-1][j] > t[i][j-1])
				{
					t[i][j] = t[i-1][j];
					b[i][j] = 1; // up
				}
				else
				{
					t[i][j] = t[i][j-1];
					b[i][j] = 2; // left
				}
			}		
		}
	}
	printf("Table:\n");
	for (i = 0; i <= m; ++i)
	{
		for (j = 0; j <= n; ++j)
		{
			printf("%d  ", t[i][j]);
		}
		printf("\n");
	}
	printf("Backtrack table:\n");
	for (i = 0; i <= m; ++i)
	{
		for (j = 0; j <= n; ++j)
		{
			printf("%d  ", b[i][j]);
		}
		printf("\n");
	}
}