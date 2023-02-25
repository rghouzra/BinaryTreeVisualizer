/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:23:15 by rghouzra          #+#    #+#             */
/*   Updated: 2023/02/25 19:23:19 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_tree.h"

void print_in_dot(t_tree *node,int i, int *count) 
{
    if (node == 0x0)
        return;
    int node_id = ++(*count);
    printf("  node%d [label=\"%s \"];\n", node_id, node->value);
    if (i != -1337)
        printf("  node%d -> node%d;\n",i,node_id);
    print_in_dot(node->left,node_id,count);
    print_in_dot(node->right,node_id,count);
}

void print_tree(t_tree *root)
 {
    printf("digraph {\n");
    int count = 0;
    print_in_dot(root, -1337, &count);
    printf("}\n");
}
