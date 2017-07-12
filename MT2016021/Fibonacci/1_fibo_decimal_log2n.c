/*
Name : Archana R
Roll : MT2016021

Program to find the Nth fibonacci number, where is N is a large number in the form of 10^digits.
Using decimal : Complexity log^2 n

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

	int arr[digits];
	int i;

	//Generate each digit randomly
	for(i=0;i<digits;i++)
	{
		arr[i] = rand()%10;
		//printf("%d", arr[i]);
	}	
	//printf("\n");

	clock_t begin = clock();
	int res = fib(arr, digits);
	clock_t end = clock();

	printf("RESULT : %d\n", res);
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("time : %lf\n",time_spent);

	return 0;
}


int fib(int arr[], int digits)
{
	
	int current_length = digits-1;
	int start = 0;
	int i;
	int current_start = start;
	int y[2][2] = {{1,0},{0,1}};
	int a[2][2] = {{1,1},{1,0}};
	
	while( current_start <=current_length)
	{
		if(arr[current_length]%2!=0)
		{
			multiply(y,a);
		}
		multiply(a,a);
		//divide the array/2
		current_start = divide(arr,digits,current_start);
		
	}
	printf("%d %d \n%d %d\n", y[0][0], y[0][1], y[1][0], y[1][1]);
	return y[1][0];
	

}


int divide(int arr[], int len, int start)
{
	int current_length = len;
	int current_start = start;
	int i;
	int carry=0;
	if(arr[current_start] == 1)
	{
		current_length -= 1;
		carry = 1;
		arr[current_start] = 0;
		current_start += 1;
		
	}
	for(i=current_start;i<len;i++)
	{
		if(carry == 1)
		{
			arr[i] = 10 + arr[i];
		}

		if(arr[i]%2 == 0)
		{
			carry = 0;
		}
		else
		{
			carry =1;
		}
		arr[i] = arr[i]/2;
	}

	return current_start;
}



/*
Multiply two 2X2 matrix and the result is stored in the first parameter array
*/
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

// To check if the number is zero
int isNumberZero(int arr[], int start, int len)
{
	int i;
	int flag = 1;
	for (i = start; i < len; ++i)
	{
		if(arr[i]!=0)
		{
			flag = 0;
			break;
		}
	}
	if(flag == 0)
	{
		return 0; //  non zero 
	}
	else
	{
		return 1; // zero
	}
}