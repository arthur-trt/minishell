/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:12:48 by jcueille          #+#    #+#             */
/*   Updated: 2021/03/26 16:41:56 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_env		*g_env;

void		ft_new_env(void)
{
	t_env	*tmp;

	g_env = malloc(sizeof(t_env));
	g_env->key = ft_strdup("VAR");
	g_env->value = ft_strdup("VALUE");
	tmp = malloc(sizeof(t_env));
	g_env->next = tmp;
	tmp->key = ft_strdup("VARZ");
	tmp->value = ft_strdup("VA     LUW");
	tmp->next = NULL;
}

/*
**	ADDS S TO COMMAND LIST WHEN SPLITTING SPACE IS REACHED
*/

int			ft_empty_buffer(char **s, t_list **command)
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

int			ft_check_char(t_list *command, char **res, char *s, int *i)
{
	int		r;

	r = 0;
	if (s[*i] == '\"')
	{
		if ((r = ft_apply_double(s, i, &ft_double, res)))
			return (ft_double_error(r, command, *res));
	}
	else if (s[*i] == '\'')
		*res = ft_apply(s, i, &ft_single, *res);
	else if (s[*i] == '$')
		*res = ft_apply_var(s, i, *res);
	else
		*res = ft_apply(s, i, &ft_string, *res);
	if (!(*res))
		return (ft_parse_error(command));
	return (r);
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
			if (ft_check_char(command, &res, s, &i))
				return (NULL);
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

void		ft_free_env(void)
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
	s = ft_strdup("\"\"");
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
