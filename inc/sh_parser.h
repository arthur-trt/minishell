/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:58:32 by jcueille          #+#    #+#             */
/*   Updated: 2021/03/31 12:52:09 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_PARSER_H
# define SH_PARSER_H
#include <stdio.h>
#include <stdlib.h>

char	*ft_double(char *s, int *i, int *r);
char	*ft_concat(t_list *list, int len);
char	*ft_alloc_concat(int len, t_list *list);

int		ft_quoted_esc(char *s, int *i, t_list **list, int *len);
int		ft_dollar(char *s, int *i, t_list **list, int *len);
int		ft_quoted_str(char *s, int *i, t_list **list, int *len);

char	*ft_search_var(char *s, int *inc, int *i);

char	*ft_string(char *s, int *i);

char	*ft_single(char *s, int *i);

int		ft_parse_error(t_list *command);
int		ft_double_error(int r, t_list *command, char *res);

void	ft_listclear(t_list **lst);
void	ft_remove_char(char *s, int i);

#endif