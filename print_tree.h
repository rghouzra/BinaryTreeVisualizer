#ifndef PRINT_TREE_H
# define PRINT_TREE_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct t_tree {
    void *value;
    struct t_tree *left;
    struct t_tree *right;
} t_tree;

typedef enum {
    FORMAT_DOT,
    FORMAT_JSON
} OutputFormat;

typedef enum {
    TRAVERSAL_PREORDER,
    TRAVERSAL_INORDER,
    TRAVERSAL_POSTORDER
} TraversalOrder;

void print_in_dot(t_tree *node, int i, int *count, FILE *fp);
void print_in_json(t_tree *node, FILE *fp, int indent);
void print_tree(t_tree *root, const char *filename, OutputFormat format, TraversalOrder order);

#ifdef __cplusplus
}
#endif
#endif