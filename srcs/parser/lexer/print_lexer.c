/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:22:52 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/05 15:46:12 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_lexer(t_lexer *lexer)
{
	t_lexer *tmp;

	tmp = lexer;
	while (tmp)
	{
		printf("cmd : %s\n", tmp->cmd);
		printf("token_type : %d\n\n", tmp->token);
		tmp = tmp->next;
	}
}