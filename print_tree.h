#ifndef PRINT_TREE_H
# define PRINT_TREE_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>

# define nullptr (void *)0x0
typedef struct s_tree
{	
	void *value;
	struct s_tree *left;
	struct s_tree *right;
}t_tree;
void print_tree(t_tree *root);
#endif
