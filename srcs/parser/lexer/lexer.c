/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:59:07 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/05 15:49:07 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int		continue_while_quote(char *str, int pos)
{
	char	quote;

	quote = str[pos];
	pos++;
	while (str[pos] && str[pos] != quote)
		pos++;
	return (pos);
}

t_token	find_previous_token(char *str, int last_pos)
{
	t_token	token;

	token = T_NO;
	if (str[last_pos] == SEMICOLON)
		token = T_SEMICOLON;
	else if (str[last_pos] == PIPE)
		token = T_PIPE;
	return (token);
}

t_lexer	*lexer(char *input)
{
	t_lexer	*lexer;
	int		i;
	int		last_pos;

	lexer = NULL;
	i = 0;
	last_pos = 0;
	while (input[i] != '\0')
	{
		if (input[i] == QUOTE || input[i] == DQUOTE)
			i = continue_while_quote(input, i);
		else if (input[i] == PIPE || input[i] == SEMICOLON)
		{
			add_cmd_to_lexer(
				&lexer,
				ft_substr(input, last_pos + 1, i - last_pos -1),
				find_previous_token(input, last_pos)
			);
			last_pos = i;
		}
		i++;
	}
	add_cmd_to_lexer(
		&lexer,
		ft_substr(input, last_pos, i - last_pos),
		find_previous_token(input, last_pos)
	);
	return (lexer);
}