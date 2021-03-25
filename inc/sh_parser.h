/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:58:32 by jcueille          #+#    #+#             */
/*   Updated: 2021/03/25 16:06:16 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_PARSER_H
# define SH_PARSER_H
#include <stdio.h>
#include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;


char	*ft_double(char *s, int *i, int *r);

void	ft_parse_error(t_list *command);
void	ft_double_error(int r, t_list *command, char *res);



#endif