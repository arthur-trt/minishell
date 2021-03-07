/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:28:22 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/05 18:04:56 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lexer(t_lexer **lexer)
{
	t_lexer	*tmp;
	t_lexer	*next;

	if (lexer)
	{
		tmp = *lexer;
		while(tmp)
		{
			next = tmp->next;
			free(tmp->cmd);
			free(tmp);
			tmp = next;
		}
		*lexer = NULL;
	}
}
