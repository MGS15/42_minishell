/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_end_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:13:43 by ozahir            #+#    #+#             */
/*   Updated: 2022/09/03 20:47:49 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int	sfilerules(char c)
{
	if (c == '\0' || c == '|' || c == ' ')
		return (1);
	return (0);
}

int	filerules(char c)
{
	if (c == '<' || c == '>' || c == '\0' || c == '|' || c == ' ')
		return (1);
	return (0);
}
