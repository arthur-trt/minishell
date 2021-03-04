/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:22:52 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/01 16:25:39 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_lexer(t_lexer lexer)
{
	t_lexer tmp;

	tmp = lexer;
	while (tmp.next != NULL)
	{
		printf("cmd : %s\n", tmp.cmd);
		printf("pipe right : %d\n", tmp.pipe_right);
		printf("pipe_left : %d\n", tmp.pipe_left);
		tmp = *(tmp.next);
	}
}
