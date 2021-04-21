/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:12:48 by jcueille          #+#    #+#             */
/*   Updated: 2021/04/21 17:01:50 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern	t_glob *g_glob;

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
