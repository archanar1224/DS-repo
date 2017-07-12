/*
Name : Archana R
Roll : MT2016021

Program to find the Nth fibonacci number, where is N is a large decimal number in the form of 10^digits. 
Using Periodic Sequence. where p <= 6m. Find only till p, store them and return Fibo(n%p).
starting from 0 1 1 2 3 5 8
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void multiply(int a[2][2], int b[2][2]);


int main(int argc, char const *argv[])
{	
	srand(time(NULL));
	
	int digits;
	int modulo;
	printf("Enter number of digits\n");
	scanf("%d",&digits);
	printf("Enter m (modulo)\n");
	scanf("%d",&modulo);

	int p_size = 6*modulo;
	char patt[p_size];
	char arr[digits];
	int i;
	for(i=0;i<digits;i++)
	{
		arr[i] = rand()%10;
		//printf("%d", arr[i]);
	}
	//printf("\n");
	
	clock_t begin = clock();
	int p = pattern(patt,p_size,modulo); 

	// now find n%p
	int ans = 0;
	for (i = 0; i < digits; ++i)
	{
		ans = (ans*10 + arr[i])%modulo;
	}
	clock_t end = clock();
	printf("N mod P : %d \nFibo: %d\n",ans, patt[ans-1]);
	
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time : %lf\n",time_spent);

	return 0;
}

int pattern(char patt[], int p, int m)
{
	int a,b,c;
	int count;
	int i;

	patt[0] = 0;
	patt[1] = 1;
	int prev = 0;
	int current = 1;
	for(i=2;i<=p;i++)
	{
		prev = current;
		current = fib(i,m);
		patt[i] = current;
		if(current == 1 && prev == 0)
		{
			//pattern found, stop
			break;
		}
		
	}
	return i-1;
}

int fib(int n, int m)
{

	int a,b,c;
	int temp;
	a = 0;
	b = 1;
	int i=1;
	if(n<2)
	{
		return n;
	}
	
	while(i<n)
	{
		c = (a + b)%m;
		a = b;
		b = c;
		i++;

	}
	
	return c;
}