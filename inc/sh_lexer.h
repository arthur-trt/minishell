/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:58:54 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/01 18:45:33 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_LEXER_H
# define SH_LEXER_H

typedef struct		s_lexer
{
	char			*cmd;
	bool			pipe_right;
	bool			pipe_left;
	struct s_lexer	*next;
}					t_lexer;

void	add_cmd_to_lexer(t_lexer **lexer, char *in, bool left, bool right);
t_lexer	*lexer(char *input);
void	print_lexer(t_lexer lexer);

#endif
