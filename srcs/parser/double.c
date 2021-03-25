/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:03:49 by jcueille          #+#    #+#             */
/*   Updated: 2021/03/25 16:06:20 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_parser.h"

char	*ft_double(char *s, int *i, int *r)
{
	t_list	*list;
	char	*res;
	int		len;

	len = 0;
	list = NULL;
	res = NULL;
	(*i)++;
	while (s[*i] && s[*i] != '\"')
	{
		if (s[*i] == '$')
			(*r) = ft_dollar(s, i, &list, &len);
		else if (s[*i] == '\\')
			(*r) = ft_quoted_esc(s, i, &list, &len);
		else
			(*r) = ft_quoted_str(s, i, &list, &len);
		if (*r)
		{
			ft_listclear(&list);
			return (NULL);
		}
		(*i)++;
	}
	if (s[*i] != '\"')
	{
		(*r) = -3;
		ft_listclear(&list);
	}
	if (list)
		res = ft_concat(list, len);
	return (res);
}