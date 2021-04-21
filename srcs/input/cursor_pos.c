/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:01:12 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/18 15:32:52 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Allows you to obtain the current position of the cursor in the terminal.
**	Writes the escape sequence: "\e[6n]", then reads a response in the terminal
**	of the form: "[<ROW>;<COL>R"
**
**	@return Structure containing the position in rows and columns
*/
t_size	get_current_cursor_position(void)
{
	t_size	pos;
	char	answer[10];
	int		i;

	ft_bzero(answer, 10);
	ft_putstr_fd("\e[6n", 0);
	read(0, answer, 10);
	i = 2;
	pos.row = ft_atoi(answer + i);
	while (ft_isdigit(answer[i]))
		i++;
	pos.col = ft_atoi(answer + i);
	return (pos);
}
