/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:59:07 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/01 18:46:02 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*lexer(char *input)
{
	t_lexer	*lexer;
	int		i;
	int		last_pipe;

	lexer = malloc(sizeof(t_lexer));
	lexer->next = NULL;
	i = 0;
	last_pipe = 0;
	while (input[i] != '\0')
	{
		if (input[i] == PIPE)
		{
			add_cmd_to_lexer(
				&lexer,
				ft_substr(input, last_pipe, i),
				true,
				true
			);
			last_pipe = i;
		}
		i++;
	}
	return lexer;
}
