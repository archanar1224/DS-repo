/*
Program to generate N numbers and store in a file.
Assuming the range of numbers is 1000 (mod)
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int n;
	printf("Enter size N\n");
	scanf("%d",&n);
	FILE *fp = fopen("input.txt","w");
	int mod = 1000;
	int i, element;
	for (i = 0; i < n; ++i)
	{
		element = rand()%mod + 1;
		fprintf(fp, "%d ", element);
	}
	fclose(fp);
	return 0;
}