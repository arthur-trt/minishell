/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_to_lexer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:18:14 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/05 15:24:08 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_cmd_to_lexer(t_lexer **lexer, char *in, t_token token)
{
	t_lexer	*tmp;
	t_lexer *new;

	new = malloc(sizeof(t_lexer));
	if (*lexer == NULL)
	{
		*lexer = new;
		tmp = *lexer;
	}
	else
	{
		tmp = *lexer;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		tmp = tmp->next;
	}
	tmp->cmd = in;
	tmp->token = token;
	tmp->next = NULL;
}
