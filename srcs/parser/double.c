/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:03:49 by jcueille          #+#    #+#             */
/*   Updated: 2021/04/21 16:04:44 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_parser.h"
#include "../libftprintf/includes/libftprintf.h"

char		*ft_alloc_concat(int len, t_list *list)
{
	char	*res;

	if (!(res = ft_calloc(len + 1, sizeof(char))))
	{
		ft_listclear(&list);
		return (NULL);
	}
	return (res);
}

char		*ft_concat(t_list *list, int len)
{
	t_list	*tmp;
	char	*res;
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	if (!(res = ft_alloc_concat(len, list)))
		return (NULL);
	tmp = list;
	while (tmp)
	{
		ptr = tmp->content;
		j = 0;
		while (ptr[j])
		{
			res[i] = ptr[j];
			i++;
			j++;
		}
		tmp = tmp->next;
	}
	ft_listclear(&list);
	return (res);
}

static int	ft_check_double(char *s, int *i, int *len, t_list **list)
{
	int		r;

	while (s[*i] && s[*i] != '\"')
	{
		if (s[*i] == '$')
			r = ft_dollar(s, i, list, len);
		else if (s[*i] == '\\')
			r = ft_quoted_esc(s, i, list, len);
		else
			r = ft_quoted_str(s, i, list, len);
		if (r)
		{
			ft_listclear(list);
			return (r);
		}
		(*i)++;
	}
	return (r);
}

char		*ft_double(char *s, int *i, int *r)
{
	t_list	*list;
	char	*res;
	int		len;

	len = 0;
	list = NULL;
	res = NULL;
	(*i)++;
	if ((*r) = ft_check_double(s, i, &len, &list))
		return (NULL);
	if (s[*i] != '\"')
	{
		(*r) = -3;
		ft_listclear(&list);
	}
	if (list)
		res = ft_concat(list, len);
	return (res);
}
