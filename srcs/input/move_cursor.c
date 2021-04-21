/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:47:31 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 16:56:28 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Move the cursor to the left
**
**	@param input Structure t_line
*/
void	move_cursor_left(t_line *input)
{
	t_size	pos;

	if (input->cursor == 0)
		return ;
	input->cursor--;
	pos.col = ((input->cursor_pos.col + input->cursor) % input->win_size.col);
	pos.row = input->cursor_pos.row;
	tputs(tgoto(tgetstr("cm", NULL), pos.col, pos.row), 1, &outfun);
}

/*
**	Move the cursor to the right
**
**	@param input Structure t_line
*/
void	move_cursos_right(t_line *input)
{
	t_size	pos;

	if (input->cursor + 1 >= MAX_CMD_LINE || input->cursor >= input->lenght)
		return ;
	input->cursor++;
	pos.col = ((input->cursor_pos.col + input->cursor) % input->win_size.col);
	pos.row = input->cursor_pos.row;
	tputs(tgoto(tgetstr("cm", NULL), pos.col, pos.row ), 1, &outfun);
}
