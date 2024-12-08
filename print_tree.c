#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "print_tree.h"

#define UNUSED(x) (void)(x)

void print_in_dot(t_tree *node, int i, int *count, FILE *fp) 
{
    if (node == NULL)
        return;
    int node_id = ++(*count);
    if (i != -1){
        fprintf(fp, "  node%d -> node%d;\n", i, node_id);
    }
    fprintf(fp, "  node%d [label=\"%s\"];\n", node_id, (char *)node->value);
    print_in_dot(node->left, node_id, count, fp);
    print_in_dot(node->right, node_id, count, fp);
}

void print_in_json(t_tree *node, FILE *fp, int indent)
{
    if (node == NULL)
        return;
    for (int i = 0; i < indent; i++) fprintf(fp, "  ");
    fprintf(fp, "{\n");
    for (int i = 0; i < indent + 1; i++) fprintf(fp, "  ");
    fprintf(fp, "\"value\": \"%s\",\n", (char *)node->value);
    for (int i = 0; i < indent + 1; i++) fprintf(fp, "  ");
    fprintf(fp, "\"left\": ");
    if (node->left) {
        fprintf(fp, "\n");
        print_in_json(node->left, fp, indent + 2);
        for (int i = 0; i < indent + 1; i++) fprintf(fp, "  ");
    } else {
        fprintf(fp, "null");
    }
    fprintf(fp, ",\n");
    for (int i = 0; i < indent + 1; i++) fprintf(fp, "  ");
    fprintf(fp, "\"right\": ");
    if (node->right) {
        fprintf(fp, "\n");
        print_in_json(node->right, fp, indent + 2);
        for (int i = 0; i < indent + 1; i++) fprintf(fp, "  ");
    } else {
        fprintf(fp, "null");
    }
    fprintf(fp, "\n");
    for (int i = 0; i < indent; i++) fprintf(fp, "  ");
    fprintf(fp, "}");
}

void print_tree(t_tree *root, const char *filename, OutputFormat format, TraversalOrder order)
{
	// still be able to define order
    UNUSED(order);

    FILE *fp;
    int count = 0;

    if (filename != NULL) {
        fp = fopen(filename, "w");
        if (fp == NULL) {
            fprintf(stderr, "error opening file %s: %s\n", filename, strerror(errno));
            exit(1);
        }
    } else {
        fp = stdout;
    }

    if (format == FORMAT_DOT) {
        fprintf(fp, "digraph {\n");
        print_in_dot(root, -1, &count, fp);
        fprintf(fp, "}\n");
    } else if (format == FORMAT_JSON) {
        print_in_json(root, fp, 0);
        fprintf(fp, "\n");
    }

    if (fp != stdout) {
        fclose(fp);
    }
}