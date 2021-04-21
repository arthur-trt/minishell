/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:02:19 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 16:33:24 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <minishell.h>

static void	init_struct(t_line *ínput)
{
	ínput->cursor_pos.row = 0;
	ínput->cursor_pos.col = 0;
	ínput->cursor = 0;
	ínput->win_size.row = 0;
	ínput->win_size.col = 0;
	ínput->lenght = 0;
	ft_bzero(ínput->line, MAX_CMD_LINE);
}

static void	special_keys(t_line *input, int key_code)
{
	if (key_code == KEY_LEFT)
		move_cursor_left(input);
	if (key_code == KEY_RIGHT)
		move_cursos_right(input);
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
