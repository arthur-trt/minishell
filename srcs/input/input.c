/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:02:19 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/23 20:15:31 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	init_struct(t_line *input)
{
	input->cursor_pos.row = 0;
	input->cursor_pos.col = 0;
	input->cursor = 0;
	input->win_size.row = 0;
	input->win_size.col = 0;
	input->lenght = 0;
	ft_bzero(input->line, MAX_CMD_LINE);
}

static void	special_keys(t_line *input, int key_code)
{
	if (key_code == KEY_LEFT)
		move_cursor_left(input);
	if (key_code == KEY_RIGHT)
		move_cursor_right(input);
	if (key_code == 127)
		delete_char(input);
	if (key_code == KEY_DC)
		delete_char_after(input);
	if (key_code == KEY_HOME)
		move_cursor_to_start(input);
	if (key_code == KEY_END)
		move_cursor_to_end(input);
	if (key_code == KEY_CTRL_LEFT)
		move_cursor_left_word(input);
	if (key_code == KEY_CTRL_RIGHT)
		move_cursor_right_word(input);
}

static void	input_loop(t_line *input)
{
	int	key_code;

	while (true)
	{
		key_code = get_key();
		special_keys(input, key_code);
		if (ft_isprint(key_code))
		{
			insert_char(input, key_code);
		}
		if (key_code == '\n')
			break ;
	}
}

/*
**	Main function of the input. Read from the standard input
**
**	@return String of what the user typed
*/
char	*input(void)
{
	t_line	input;

	init_struct(&input);
	set_term_raw_mode();
	input.cursor_pos = get_current_cursor_position();
	input.win_size = get_win_size();
	input_loop(&input);
	set_term_default_mode();
	return (ft_strdup(input.line));
}
