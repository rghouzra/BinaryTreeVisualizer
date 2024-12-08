#include <stdio.h>
#include <stdlib.h>
#include "../print_tree.h"

typedef struct TreeNode {
    char *value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* create_sample_tree() {
    TreeNode* node3 = (TreeNode*)malloc(sizeof(TreeNode));
    node3->value = "C";
    node3->left = NULL;
    node3->right = NULL;

    TreeNode* node2 = (TreeNode*)malloc(sizeof(TreeNode));
    node2->value = "B";
    node2->left = NULL;
    node2->right = NULL;

    TreeNode* node1 = (TreeNode*)malloc(sizeof(TreeNode));
    node1->value = "A";
    node1->left = node2;
    node1->right = node3;

    return node1;
}

void delete_tree(TreeNode* node) {
    if (node == NULL) return;
    delete_tree(node->left);
    delete_tree(node->right);
    free(node);
}

int main() {
    TreeNode* root = create_sample_tree();

    printf("DOT format:\n");
    print_tree((t_tree*)root, NULL, FORMAT_DOT, TRAVERSAL_PREORDER);

    printf("\nJSON format:\n");
    print_tree((t_tree*)root, NULL, FORMAT_JSON, TRAVERSAL_PREORDER);

    delete_tree(root);
    return 0;
}