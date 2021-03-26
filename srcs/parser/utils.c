/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:31:24 by jcueille          #+#    #+#             */
/*   Updated: 2021/03/26 16:37:41 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf/includes/libftprintf.h"

void	ft_listclear(t_list **lst)
{
	t_list *nxt;
	t_list *tmp;

	if (*lst)
	{
		tmp = *lst;
		while (tmp)
		{
			nxt = (tmp)->next;
			free(tmp->content);
			tmp->content = NULL;
			free(tmp);
			tmp = nxt;
		}
		*lst = NULL;
	}
}

void	ft_remove_char(char *s, int i)
{
	char	*res;
	int		j;

	if (!(res = malloc(ft_strlen(s) * sizeof(char))))
		return ;
	j = -1;
	while (++j < i)
		res[j] = s[j];
	i = j;
	while (s[++j])
	{
		res[i] = s[j];
		i++;
	}
	res[j - 1] = '\0';
	free(s);
	s = ft_strdup(res);
	free(res);
}
