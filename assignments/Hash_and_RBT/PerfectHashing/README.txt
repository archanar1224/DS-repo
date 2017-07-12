1. First generate the data file by running generate.c or use the exisiting smaple datafile : "sample_data.txt"
	Example : gcc generate_data.c 
			  ./a.out sample_data.txt

2. Next run the perfect hashing over this input data file
	Example :  gcc -c 1_perfect_hash_main.c 2_perfect_hash_funs.c
			   gcc -o output 1_perfect_hash_main.o 2_perfect_hash_funs.o
			   ./output sample_data.txt

3. Then search for any number in the file.

