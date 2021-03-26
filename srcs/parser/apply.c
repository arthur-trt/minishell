/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:31:33 by jcueille          #+#    #+#             */
/*   Updated: 2021/03/26 16:41:05 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_parser.h"
#include "libftprintf.h"

char		*ft_apply(char *s, int *i, char *(*f)(char *s, int *i), char *res)
{
	char	*tmp;
	char	*tmp_bis;

	tmp_bis = NULL;
	tmp = (*f)(s, i);
	if (!(res) && tmp)
		tmp_bis = ft_strdup(tmp);
	else if (res && tmp)
		tmp_bis = ft_strjoin(res, tmp);
	free(res);
	res = NULL;
	free(tmp);
	return (tmp_bis);
}

int			ft_apply_double(char *s, int *i,
							char *(*f)(char *s, int *i, int *r), char **res)
{
	char	*tmp;
	char	*tmp_bis;
	int		r;

	r = 0;
	tmp_bis = NULL;
	tmp = (*f)(s, i, &r);
	if (!(*res) && tmp)
		tmp_bis = ft_strdup(tmp);
	else if (*res && tmp)
		tmp_bis = ft_strjoin(*res, tmp);
	free(*res);
	*res = NULL;
	free(tmp);
	*res = tmp_bis;
	return (r);
}

char		*ft_apply_var(char *s, int *i, char *res)
{
	char	*tmp;
	char	*tmp_bis;
	int		inc;

	tmp_bis = NULL;
	tmp_bis = ft_search_var(s, &inc, i);
	if (!(tmp_bis))
		return (res);
	if (res)
		tmp = ft_strjoin(res, tmp_bis);
	else
	{
		free(res);
		return (tmp_bis);
	}
	free(res);
	return (tmp);
}
