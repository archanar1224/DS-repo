/*
Name : Archana R
Roll : MT2016021
Edit distance
*/
#include <stdio.h>
int construct_table(char x[], char y[], int m, int n, int add, int del, int repl);
int main(int argc, char const *argv[])
{
	int m,n;
	printf("Enter lengths\n");
	scanf("%d %d",&m, &n);
	int i;
	char x[m+1], y[n+1];
	printf("Enter strings\n");
	scanf("%s",&x[1]);
	scanf("%s",&y[1]);
	x[0] = y[0] = '0';
	printf("Enter add, delete and replace cost\n");
	int add, del, repl;
	scanf("%d %d %d",&add,&del,&repl);
	construct_table(x, y, m, n, add, del, repl);	
	return 0;
}

int construct_table(char x[], char y[], int m, int n, int add, int del, int repl)
{
	
	int t[m+1][n+1];
	int op[m+1][n+1];
	int i=0;
	int j;
	
	t[0][0] = 0;
	for ( i = 0; i <= m; ++i)
	{
		for (j = 0; j <= n; ++j)
		{
			op[i][j] = 0;
		}
	}
	for (i = 1; i <= n; ++i)
	{		
		t[0][i] = i * add;
		op[0][i] = 1; // 1 : ADD
	}
	for (i = 1; i <= m; ++i)
	{		
		t[i][0] = i * del;
		op[i][0] = 2; // 2 :DELETE
	}
	int temp1,temp2,temp3, min1;
	for (i = 1; i <= m; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if(x[i]==y[j])			
			{
				t[i][j] = t[i-1][j-1];

			}
			else
			{
				temp1 = t[i-1][j-1] + repl;
				temp2 = t[i][j-1] + add;
				temp3 = t[i-1][j] + del;
				if(temp1 < temp2 && temp1 < temp3)
				{
					op[i][j] = 3; // 3 - REPLACE
				}
				else if(temp2 < temp1 && temp2 < temp3)
				{
					op[i][j] = 1; // ADD
				}
				else
				{
					op[i][j] = 2; // DELETE
				}


				min1 = temp1 < temp2 ? temp1 : temp2;
				t[i][j] = temp3 < min1 ? temp3 : min1;
				
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
	/*for (i = 0; i <= m; ++i)
	{
		for (j = 0; j <= n; ++j)
		{
			printf("%d  ", op[i][j]);
		}
		printf("\n");
	}*/
	printf("Backtrack:\n");
	reconstruct(n,op,m,n);
	printf("\n");
	
}

reconstruct(int n, int op[][n+1], int i, int j)
{
	int i1 = i;
	int j1 = j;
	if(i==0 && j==0)
	{
		return;
	}
	if(op[i][j] == 3 || op[i][j] == 0) // replace
	{
		i1 = i - 1;
		j1 = j - 1;
	}
	else if(op[i][j] == 2) // delete
	{
		i1 = i - 1;
		j1 = j;
	}
	else if(op[i][j] == 1) // add
	{
		i1 = i;
		j1 = j - 1;
	}
	
	reconstruct(n,op,i1,j1);
	printf(" %d ", op[i][j]);
}