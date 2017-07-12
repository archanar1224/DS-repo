/*
Name : Archana R
Roll : MT2016021

Program to find the Nth fibonacci number, where is N is a large binary number in the form of 10^digits.
Using binary : Complexity logn

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
	printf("Enter number of digits\n");
	scanf("%d",&digits);

	char arr[digits];
	arr[0] = 1;
	int i;
	for(i=1;i<digits;i++)
	{
		arr[i] = rand()%2; // either 0 or 1
		//printf("%d", arr[i]);
	}
	//printf("\n");
	
	clock_t begin = clock();
	int res = fib(arr, digits);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nRESULT : %d\n", res);
	printf("Time : %lf\n",time_spent);

	return 0;
}

int fib(char arr[], int digits)
{
	
	int current_length = digits-1;
	int start = 0;
	int i;
	int y[2][2] = {{1,0},{0,1}};
	int a[2][2] = {{1,1},{1,0}};
	
	while( current_length >= 0 )
	{
		if(arr[current_length] == 1) //odd
		{
			multiply(y,a);
			
		}
		multiply(a,a);
		//divide the array/2
		current_length -= 1;
		
	}
	printf("\n%d %d \n%d %d", y[0][0], y[0][1], y[1][0], y[1][1]);
	return y[1][0];
}

void multiply(int a[2][2], int b[2][2])
{
	int i;
	int w,x,y,z;
	
		w = (a[0][0] * b[0][0] + a[0][1] * b[1][0])%100;
		x = (a[0][0] * b[0][1] + a[0][1] * b[1][1])%100;
		y = (a[1][0] * b[0][0] + a[1][1] * b[1][0])%100;
		z = (a[1][0] * b[0][1] + a[1][1] * b[1][1])%100;
		a[0][0] = w;
		a[0][1] = x;
		a[1][0] = y;
		a[1][1] = z;
	
}