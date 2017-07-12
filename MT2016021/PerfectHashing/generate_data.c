/*
Name : Archana R
Roll : MT2016021

Generate random 10^6 10 digit numbers
*/
#include <stdio.h>
#include <stdlib.h>
// #define MIN 9000000000 //generates 10 digit numbers starting from 9

#define MIN 1000000000
#define LEN 10000000000
#define SIZE 1000000

int main(int argc, char const *argv[])
{
	if(argc<2)
	{
		printf("Provide the file to write as an argument\n");
		exit(1);
	}
	srand(time(NULL));
	int n  = SIZE; // 10^6, 10 digit numbers
	int i;
	FILE * fp = fopen(argv[1],"w");
	for (i = 0; i < n; ++i)
	{
		long long int temp = rand() % (LEN + 1 - MIN )  + MIN; // generate number within the range (10^10)
		fprintf(fp, "%lld\n", temp); // write to file
	}
	return 0;
}