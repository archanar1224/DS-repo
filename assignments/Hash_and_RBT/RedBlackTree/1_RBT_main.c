/*
Name : Archana R
Roll : MT2016021

Reb-Black tree implementation (Insertion, Deletion)
Main driver file
*/
#include "header.h"
#include <stdlib.h>
#include <stdio.h>
void driver();
int main(int argc, char const *argv[])
{
	driver();
	return 0;
}

void driver()
{
	nil =  create_node(-1,'B');
	struct node *root = nil;
    printf("\nChoose the below options : (-999 to quit out of the option) \n");
	while(1) 
	{
		printf("\n1. Insert items\n2. Delete items\n3. Search items\n4. Traverse tree\n5. Exit\n");          
		int choice;
		scanf("%d",&choice);
		int data;
		switch (choice) 
		{
			case 1:	scanf("%d",&data);
                    while(data != -999) 
                    {
                    	struct node *new_node = create_node(data,'R');
                    	root = insert(root,new_node);
                    	scanf("%d",&data);
                    }
                    traverse_tree(root);
                   
                    break;

                case 2: scanf("%d",&data);
                    
                    	while (data != -999) 
                    	{
                        	root = rbt_delete(root, data);
                        	scanf("%d",&data);
                        }
                        traverse_tree(root);
                    	break;

                case 3: scanf("%d",&data);
                    	while (data != -999) 
                    	{
                        	struct node *res = search(root,data);
                        	if(res == NULL)
                        	{
                        		printf(" %d Not found\n",data);
                        	}
                        	else
                        	{
                        		printf("%d Found\n",data);
                        	}
                        	scanf("%d",&data);
                        }
                    	break;
                case 4: traverse_tree(root);
                    	break;
                case 5: exit(0);
            }
        }
}