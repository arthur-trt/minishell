/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:31:34 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 15:44:38 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	insert_char(t_line *input, int c)
{
	if (input->lenght + 1 >= MAX_CMD_LINE)
		return (false);
	ft_memmove(input->line + input->cursor, input->line + input->cursor - 1,
		input->lenght - input->cursor + 1);
	input->line[input->cursor] = c;
	input->lenght++;
	input->cursor++;
	tputs(tgetstr("im", NULL), 2, &outfun);
	outfun(c);
	tputs(tgetstr("ei", NULL), 2, &outfun);
	return (true);
}
