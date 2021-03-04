/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_to_lexer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:18:14 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/01 18:46:16 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_cmd_to_lexer(t_lexer **lexer, char *in, bool left, bool right)
{
	t_lexer	*tmp;
	t_lexer *new;

	tmp = *lexer;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new = malloc(sizeof(t_lexer));
	tmp->next = new;
	tmp = tmp->next;
	tmp->cmd = in;
	tmp->pipe_left = left;
	tmp->pipe_left = right;
	tmp->next = NULL;
}
