/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:17:11 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/11 15:18:25 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
# define BINARY_TREE_H

# include "minishell.h"

t_btree	*binary_tree_new(void *root, int type);
void	binary_tree_clear(t_btree **root);
int		binary_tree_add_r_child(t_btree **root, t_btree *r_child);
int		binary_tree_add_l_child(t_btree **root, t_btree *l_child);
t_btree	*binary_tree_create(t_stack *simple_cmd, t_stack *op);
void	print_tree(const char *prefix, t_btree *root, int is_left);
void	binary_tree_free(t_btree **root);


#endif