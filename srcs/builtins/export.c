/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:38:43 by jcueille          #+#    #+#             */
/*   Updated: 2021/03/29 16:51:54 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf/includes/libft.h"
#include "../../sh_parser.h"

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

char	*ft_concat(t_list *list, int len)
{
	t_list	*tmp;
	char	*res;
	int		i;
	int		j;

	i = 0;
	if (!(res = ft_calloc(len + 1, sizeof(char))))
	{
		ft_listclear(&list);
		return (NULL);
	}
	tmp = list;
	while (tmp)
	{
		j = 0;
		while (tmp->content[j])
		{
			res[i] = tmp->content[j];
			i++;
			j++;
		}
		tmp = tmp->next;
	}
	ft_listclear(&list);
	return (res);
}

int			ft_str_isalnum(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(ft_isalnum(s[i])))
			return (0);
		i++;
	}
	return (1);
}

int		ft_concat_value(t_env *env, char **split)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;


	i = 1;
	while (split[i])
	{
		if (i == 1)
		{
			if (!(tmp = ft_strdup(split[i])))
				return (-1);
		else
		{
			if (!(tmp2 = ft_strjoin(" ", split[i])))
				return (-2);
			if (!(tmp3 = ft_strjoin(tmp, tmp2)))
				return (-3);
			free(tmp);
			free(tmp2);
			tmp = tmp3;
		}
		i++;
	}
	return (0);
}

int			*ft_search_keyvalue(char **split, t_env *env)
{
	if (!(ft_str_isalnum(split[0])))
		return (0);
	if (!(env->key = ft_strdup(split[0])))
		return (-1);
	if (split[1])
	{
		if (ft_concat_value(env, split))
			return (-2);
	}
	return (0);
}

int		ft_export(t_list *cmd)
{
	t_env	*res;
	t_list	*tmp;

	res = NULL;
	tmp = cmd;
	while (tmp)
	{
		if (split = ft_split(tmp->content, '='))
		{
			res = ft_search_keyvalue(split, res);
		}
		tmp = tmp->next;
	}
}
/*
** 1. Retrieve key
**		a. Cycle throught lst
		b. Cycle throught eqch str unti = or space found
		c. Substr 0 - =
		d. Passer le lst et la position de = a retrieve value
** 2. Retrieve value
**		tant que str != space ou \0
**		substr
** 3. Add key value to path
	check if key aready exists
		remove maillon if so
	create maillon with key value
	add to path
*/