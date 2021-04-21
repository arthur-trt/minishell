/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_input.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:57:00 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/20 20:11:42 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_INPUT_H
# define SH_INPUT_H

# include <curses.h>
# include <term.h>

# include "minishell.h"

# define MAX_CMD_LINE	4096

# define KEY_CODE_UP	"\x1b\x5b\x41\0"
# define KEY_CODE_DOWN	"\x1b\x5b\x42\0"
# define KEY_CODE_RIGHT	"\x1b\x5b\x43\0"
# define KEY_CODE_LEFT	"\x1b\x5b\x44\0"

typedef struct	s_size
{
		size_t	row;
		size_t	col;
}				t_size;

typedef struct	s_line
{
		char	line[MAX_CMD_LINE];
		size_t	lenght;
		size_t	cursor;
		t_size	cursor_pos;
		t_size	win_size;
}				t_line;

void	set_term_default_mode(void);
void	set_term_raw_mode(void);

t_size	get_win_size(void);

int		get_key(void);

t_size	get_current_cursor_position(void);
bool	insert_char(t_line *input, int c);

int	outfun(int c);
char	*input(void);

void	move_cursor_left(t_line *input);
void	move_cursos_right(t_line *input);

#endif
