/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:09:45 by rghouzra          #+#    #+#             */
/*   Updated: 2023/02/25 19:17:08 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_TREE_H
# define PRINT_TREE_H
#include <stdio.h>
#include <stdlib.h>
typedef struct s_tree
{	
	void *value;
	struct s_tree *left;
	struct s_tree *right;
}t_tree;
void print_tree(t_tree *root, char *s);
#endif
