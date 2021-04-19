/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:15:15 by jcueille          #+#    #+#             */
/*   Updated: 2021/04/19 20:46:06 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern t_glob *g_glob;

static int	ft_bracket_check(char *s, int i)
{
	while (s[i])
	{
		if (s[i] == '}')
			return (1);
		i++;
	}
	printf("ERROR: BRACKET MISSING\n");
	return (0);
}

static char	*ft_add_space(char **ss, int i, char *tmp)
{
	char	*spaced;
	char	*joined;

	spaced = NULL;
	if (!(spaced = ft_strjoin(ss[i], " ")))
		return (NULL);
	if (tmp)
	{
		joined = ft_strjoin(tmp, spaced);
		free(tmp);
		return (joined);
	}
	return (spaced);
}

static char	*ft_remove_spaces(char *s)
{
	char	**ss;
	char	*tmp;
	char	*res;
	int		i;

	i = -1;
	res = 0;
	tmp = NULL;
	res = NULL;
	ss = ft_split(s, ' ');
	free(s);
	while (ss[++i])
	{
		if (!(tmp) && !(ss[i + 1]))
			res = ft_strdup(ss[i]);
		else if (ss[i + 1])
			tmp = ft_add_space(ss, i, tmp);
		else
			res = ft_strjoin(tmp, ss[i]);
		free(ss[i]);
	}
	free(tmp);
	if (ss)
		free(ss);
	return (res);
}

static void	ft_search_value(char *name, char **res, int *inc)
{
	t_env	*tmp;

	tmp = g_glob->env;
	while (tmp)
	{
		if (!(ft_strcmp(name, tmp->key)))
			*res = ft_strdup(tmp->value);
		tmp = tmp->next;
	}
	free(name);
	if (*res)
		*res = ft_remove_spaces(*res);
}

char		*ft_ret_var(void)
{
	char	*res;

	res = ft_itoa(g_glob->ret);
	return (NULL);
}

char		*ft_search_var(char *s, int *inc, int *i)
{
	int		j;
	char	*name;
	char	*res;

	(*i)++;
	res = NULL;
	if (!(s[*i]))
		return (res);
	if (s[*i] == '{')
	{
		if (!(ft_bracket_check(s, *i)))
			return (res);
		(*inc) = 1;
		(*i)++;
	}
	j = *i;
	if (s[*i] == '?')
		return (ft_ret_var());
	while (s[*i] && s[*i] != ' ' && s[*i] != '}' && s[*i] != '\"')
		(*i)++;
	if (*i - j == 0)
		return (NULL);
	name = ft_substr(s, j, *i - j);
	ft_search_value(name, &res, inc);
	if (s[*i] == '"')
		(*i)--;
	return (res);
}
