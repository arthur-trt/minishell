/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:12:48 by jcueille          #+#    #+#             */
/*   Updated: 2021/03/25 19:15:04 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../libftprintf/includes/libftprintf.h"
#include "../../inc/minishell.h"

t_env *g_env;

void	ft_new_env(void)
{
	t_env *tmp;

	g_env = malloc(sizeof(t_env));
	g_env->key = ft_strdup("VAR");
	g_env->value = ft_strdup("VALUE");
	tmp = malloc(sizeof(t_env));
	g_env->next = tmp;
	tmp->key = ft_strdup("VARZ");
	tmp->value = ft_strdup("VA     LUW");
	tmp->next = NULL;
}

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

/*
**	REMOVE A SINGLE CHAR FROM A STRING
*/

static void	ft_remove_char(char *s, int i)
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

/*
**	CHECKS IF VAR BRACKETS ARE CLOSED
*/

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

/*
**	STRING SANS QUOTES
*/

static char	*ft_string(char *s, int *i)
{
	int		j;
	char	*res;

	j = *i;
	while (s[j] && s[j] != ' ' && s[j] != '\"' && s[j] != '\'' && s[j] != '$')
	{
		if (s[j] == '\\')
		{
			ft_remove_char(s, j);
			j--;
		}
		j++;
	}
	res = ft_substr(s, *i, j - *i);
	(*i) = j - 1;
	return (res);
}

static char	*ft_single(char *s, int *i)
{
	int		j;
	char	*res;

	j = (*i) + 1;
	while (s[j] && s[j] != '\'')
		j++;
	res = ft_substr(s, (*i) + 1, j - (*i + 1));
	(*i) = j;
	return (res);
}

char	*ft_add_space(char **ss, int i, char *tmp)
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

char	*ft_remove_spaces(char *s)
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
	return (res);
}

/*
**	RETRIEVE VAR VALUE
*/

void		ft_search_value(char *name, char **res, int *inc)
{
	t_env	*tmp;

	tmp = g_env;
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

static char	*ft_search_var(char *s, int *inc, int *i)
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

int	ft_quoted_str(char *s, int *i, t_list **list, int *len)
{
	int		j;
	char	*res;
	t_list	*tmp;

	j = *i;
	while (s[j] && s[j] != '\"' && s[j] != '\\' && s[j] != '$')
		j++;
	if (!(res = ft_substr(s, *i, j - *i)))
		return (-1);
	if (!(tmp = ft_lstnew(res)))
	{
		free(res);
		return (-2);
	}
	ft_lstadd_back(list, tmp);
	*i = j - 1;
	(*len) += ft_strlen(res);
	return (0);
}

int			ft_dollar(char *s, int *i, t_list **list, int *len)
{
	char	*res;
	int		inc;
	t_list	*tmp;

	inc = 0;
	if (!(res = ft_search_var(s, &inc, i)))
		return (0);
	if (!(tmp = ft_lstnew(res)))
		return (-1);
	ft_lstadd_back(list, tmp);
	(*len) += ft_strlen(res);
	return (0);
}

static int	ft_quoted_esc(char *s, int *i, t_list **list, int *len)
{
	char	*res;
	t_list	*tmp;

	(*i)++;
	if (!(s[*i]))
		return (0);
	if (!(res = ft_substr(s, *i, 1)))
		return (-1);
	if (!(tmp = ft_lstnew(res)))
	{
		free(res);
		return (-2);
	}
	ft_lstadd_back(list, tmp);
	(*len) += ft_strlen(res);
	return (0);
}

char	*ft_alloc_concat(int len, t_list *list)
{
	char	*res;

	if (!(res = ft_calloc(len + 1, sizeof(char))))
	{
		ft_listclear(&list);
		return (NULL);
	}
	return (res);
}

char	*ft_concat(t_list *list, int len)
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

int		ft_check_char(char *s, int *i, int *len, t_list **list)
{
	int	r;

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

char	*ft_double(char *s, int *i, int *r)
{
	t_list	*list;
	char	*res;
	int		len;

	len = 0;
	list = NULL;
	res = NULL;
	(*i)++;
	if ((*r) = ft_check_char(s, i, &len, &list))
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

/*
**	APPLY FT ACCORDING TO QUOTES OR NOT
*/

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

int		ft_apply_double(char *s, int *i, char *(*f)(char *s, int *i, int *r),
						char **res)
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

char	*ft_apply_var(char *s, int *i, char *res)
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

/*
**	ADDS STR TO COMMANDS LIST WHEN SPLITTING SPACE IS REACHED
*/

int		ft_empty_buffer(char **s, t_list **command)
{
	t_list	*tmp;
	char	*copy;

	if (!(*s))
		return (0);
	if (!(copy = ft_strdup(*s)))
		return (-1);
	if (!(tmp = ft_lstnew(copy)))
		return (-2);
	ft_lstadd_back(command, tmp);
	free(*s);
	*s = NULL;
	return (0);
}

void	ft_parse_error(t_list *command)
{
	if (command)
	{
		ft_listclear(&command);
		printf("There's been a malloc error.\n");
	}
}

void	ft_double_error(int r, t_list *command, char *res)
{
	if (res)
		free(res);
	ft_listclear(&command);
	if (r == -3)
		printf("DOUBLE QUOTES NOT CLOSED\n");
	else
		printf("There's been a malloc error.\n");
}

t_list		*ft_parse(char *s)
{
	t_list	*command;
	char	*res;
	int		i;
	int		r;

	r = 0;
	i = -1;
	res = NULL;
	command = NULL;
	while (s[++i])
	{
		if (s[i] != ' ')
		{
			if (s[i] == '\"')
			{
				if ((r = ft_apply_double(s, &i, &ft_double, &res)))
				{
					ft_double_error(r, command, res);
					return (NULL);
				}
			}
			else if (s[i] == '\'')
				res = ft_apply(s, &i, &ft_single, res);
			else if (s[i] == '$')
				res = ft_apply_var(s, &i, res);
			else
				res = ft_apply(s, &i, &ft_string, res);
			if (!(res))
			{
				ft_parse_error(command);
				return (NULL);
			}
		}
		else if (s[i] == ' ')
			if (ft_empty_buffer(&res, &command))
				ft_parse_error(command);
	}
	if (res)
		if (ft_empty_buffer(&res, &command))
			ft_parse_error(command);
	return (command);
}

void	ft_free_env(void)
{
	t_env	*tmp;

	while (g_env)
	{
		tmp = g_env->next;
		free(g_env->key);
		free(g_env->value);
		free(g_env);
		g_env = tmp;
	}
}

int			main(void)
{
	char	*s;
	t_list	*command;
	t_list	*tmp;

	ft_new_env();
	s = ft_strdup("Je fais des tests 'quel plaisir' \"hamdoulilah\"${VAR} mdr \" lol ${VAR}\"");
	command = ft_parse(s);
	tmp = command;
	while (tmp)
	{
		printf("S IS %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("%s\n", s);
	free(s);
	ft_listclear(&command);
	ft_free_env();
	return (0);
}
