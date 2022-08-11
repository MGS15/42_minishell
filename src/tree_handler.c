/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:26:06 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/11 15:55:02 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

t_btree	*binary_tree_new(void *root, int type)
{
	t_btree	*node;

	node = (t_btree *) malloc(sizeof(t_btree));
	if (!node)
		return (NULL);
	node->content = root;
	node->e_type = type;
	node->l_child = NULL;
	node->r_child = NULL;
	return (node);
}

int	binary_tree_add_r_child(t_btree **root, t_btree *r_child)
{
	if (*root)
	{
		(*root)->r_child = r_child;
		return (0);
	}
	return (1);
}

int	binary_tree_add_l_child(t_btree **root, t_btree *l_child)
{
	if (*root)
	{
		(*root)->l_child = l_child;
		return (0);
	}
	return (1);
}

void	binary_tree_free(t_btree **root)
{
	if (!root)
		return ;
	if (!*root)
		return ;
	binary_tree_free(&((*root)->l_child));
	binary_tree_free(&((*root)->r_child));
	free(*root);
}

t_btree	*binary_tree_create(t_stack *simple_cmd, t_stack *op)
{
	t_btree	*node;

	if (!simple_cmd->size)
		return (NULL);
	if (!op->size)
		return (binary_tree_new(pop_stack(simple_cmd), CMD));
	node = binary_tree_new(pop_stack(op), OPERATION);
	if (!node)
		return (NULL);
	node->r_child = binary_tree_create(simple_cmd, op);
	node->l_child = binary_tree_create(simple_cmd, op);
	return (node);
}

void	print_tree(const char *prefix, t_btree *root, int is_left)
{
	char *prefex;

	if (!root)
		return ;
	printf("%s", prefix);
	if (is_left)
		printf("|--<");
	else
		printf("|__");
	if (!root->e_type)
		printf("[%s]\n", ((t_token*) root->content)->def);
	else
	{
		int i = -1;
		t_token **token = root->content;
		printf("[");
		while (token[++i])
			printf("%s", token[i]->def);
		printf("]\n");
	}
	if (is_left)
		prefex = ft_strjoin(prefix, "|    ");
	else
		prefex = ft_strjoin(prefix, "     ");
	print_tree(prefex, root->l_child, 1);
	print_tree(prefex, root->r_child, 0);
}