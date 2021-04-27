/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:02:19 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/27 10:32:49 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_struct(t_line *input)
{
	input->cursor_pos.row = 0;
	input->cursor_pos.col = 0;
	input->cursor = 0;
	input->win_size.row = 0;
	input->win_size.col = 0;
	input->lenght = 0;
	input->hist_pos = 0;
	ft_bzero(input->line, MAX_CMD_LINE);
}

static void	special_keys(t_line *input, int key_code, t_hist **hist)
{
	if (key_code == KEY_LEFT)
		move_cursor_left(input);
	if (key_code == KEY_RIGHT)
		move_cursor_right(input);
	if (key_code == KEY_UP)
		history_nav_up(input, hist);
	if (key_code == KEY_DOWN)
		history_nav_down(input, hist);
}

#ifdef BONUS
static void	special_bonus_keys(t_line *input, int key_code)
{
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
	if (key_code == KEY_CTRL_UP)
		move_cursor_prev_line(input);
	if (key_code == KEY_CTRL_DOWN)
		move_cursor_next_line(input);
}
#endif

static void	input_loop(t_line *input, t_hist **hist)
{
	int	key_code;

	while (true)
	{
		key_code = get_key();
		special_keys(input, key_code, hist);
		#ifdef BONUS
			special_bonus_keys(input, key_code);
		#endif
		if (ft_isprint(key_code))
		{
			insert_char(input, key_code);
		}
		if (key_code == '\n')
		{
			input->cursor = 0;
			set_cursor_pos(*input);
			break ;
		}
	}
}

/*
**	Main function of the input. Read from the standard input
**
**	@param history Linked list representing the history
**
**	@return String of what the user typed
*/
char	*input(t_hist **history)
{
	t_line				input;
	t_hist				*tmp_hist;

	tmp_hist = (*history);
	init_struct(&input);
	set_term_raw_mode();
	outfun_str("PROMTP > ");
	input.cursor_pos = get_current_cursor_position();
	input.win_size = get_win_size();
	input_loop(&input, &tmp_hist);
	append_history(input.line, history);
	set_term_default_mode();
	return (ft_strdup(input.line));
}
