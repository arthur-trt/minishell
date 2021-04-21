/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:47:31 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 16:42:57 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	move_cursor_left(t_line *input)
{
	t_size	pos;

	if (input->cursor == 0)
		return ;
	input->cursor--;
//	printf("cursor_pos:\n\tcol : %zu\nrow : %zu\n", input->cursor_pos.col, input->cursor_pos.row);
//	printf("win_size:\n\tcol : %zu\nrow : %zu\n", input->win_size.col, input->win_size.row);
	pos.col = ((input->cursor_pos.col + input->cursor) %
		input->win_size.col);
	pos.row = input->cursor_pos.row; // + input->cursor) / input->win_size.row;
	tputs(tgoto(tgetstr("cm", NULL), pos.col, pos.row), 1, &outfun);
}

void	move_cursos_right(t_line *input)
{
	t_size	pos;

	if (input->cursor + 1 >= MAX_CMD_LINE || input->cursor >= input->lenght)
		return ;
	input->cursor++;
//	printf("cursor_pos:\n\tcol : %zu\nrow : %zu\n", input->cursor_pos.col, input->cursor_pos.row);
//	printf("win_size:\n\tcol : %zu\nrow : %zu\n", input->win_size.col, input->win_size.row);
	pos.col = ((input->cursor_pos.col + input->cursor) %
		input->win_size.col);
	pos.row = input->cursor_pos.row; // + input->cursor) / input->win_size.row;
	tputs(tgoto(tgetstr("cm", NULL), pos.col, pos.row ), 1, &outfun);
}
