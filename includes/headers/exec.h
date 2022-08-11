/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:24:06 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/11 18:04:29 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EXEC_H
#define EXEC_H
void    visitor(t_btree *root, char **env);
int is_expanded(int type);
void    expan_iter(t_token   **token, char **env);
void    exec_fu(t_token **token, char **env);



# endif