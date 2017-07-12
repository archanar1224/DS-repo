/*
Name : Archana R
Roll : MT2016021

Perfect hash implementation (Insertion, Deletion)
Main file
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

long long int p = 10000000019;
int a,b;
int main(int argc, char const *argv[])
{
	
	srand(time(NULL));
	int n = SIZE;
	int i;
	if(argc<2)
	{
		printf("Provide the input file\n");
		exit(1);
	}
	
	long int m = 2*n;
	struct primary *pri = primary_hash(n,m,argv[1]);

	long int sum = find_sum(pri, m);
	//printf("2n : %d, sum : %ld\n",2*n, sum );
	while(sum > 2*n)
	{
		pri = primary_hash(n, m, argv[1]);
		sum = find_sum(pri, m);
	}
	struct hash *myhash  = secondary_hash(pri, m, n, argv[1]);
	long long int num;
	while(1)
	{
		printf("Search : (-999 to break) \n");
		scanf("%lld",&num);
		if(num == -999)
		{
			break;
		}
		search(myhash, m, num);
	}
	/* 
	search(myhash, m, 1466866969);
	search(myhash, m, 3132718834); 
	*/
	int limit;
	while(1)
	{
		printf("|x-y| Enter the limit for pair difference.  (-999 to break)\n");
		scanf("%d", &limit);
		if(limit == -999)
		{
			break;
		}
		print_pairs(myhash,m, limit);
	}
	//printf("a : %d , b : %d\n", a,b);
	return 0;

}

