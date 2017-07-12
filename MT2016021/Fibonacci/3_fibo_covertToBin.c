/*
Name : Archana R
Roll : MT2016021

Program to find the Nth fibonacci number, where is N is a large decimal number in the form of 10^digits. 
Convert it to binary and then find the result.
Complexity log^2 n

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
	char bin[4*digits];
	int i;
	for(i=0;i<digits;i++)
	{
		arr[i] = rand()%10; // decimal
		//printf("%d", arr[i]);
		
	}
	//printf("\n");
	clock_t begin = clock();
	int bin_length = convert_to_binary(arr, bin, digits); // convert the decimal number to binary.

	int res = fib(bin, bin_length);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nRESULT: %d\n", res);
	printf("Time : %lf\n",time_spent);

	return 0;
}

int convert_to_binary(int arr[], char bin[], int digits)
{
	int count = 0;
	int end_bin;
	int i;
	int current_start_dec = 0;
	int current_len_dec = digits-1;
	while(arr[current_start_dec] == 0)
	{
		current_start_dec += 1;
	}
	while( current_start_dec <= current_len_dec)
	{
		
		bin[count++] = arr[current_len_dec]%2;
		//divide the array/2
		current_start_dec = divide(arr,digits,current_start_dec);
	}
	int j = count-1;
	int temp;
	//reverse the array
	for(i=0;i<count/2;i++)
	{
		temp = bin[i];
		bin[i] = bin[j];
		bin[j] = temp; 
		j--;
	}	
	return count;
}

int divide(int arr[], int len, int start, char bin[])
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