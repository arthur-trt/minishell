/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dquoted.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:24:11 by jcueille          #+#    #+#             */
/*   Updated: 2021/04/21 20:38:07 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
**	Handles "normal" characters inside double quotes
**	
**	@param	s user's input string
**	@param	i the position of the current character on s
**	@param	list a linked list containing the text parsed so far inside double quotes
**	@param	len the total size of all the strings contained in list
**	@return 0 if success < 0 if error
*/
int			ft_quoted_str(char *s, int *i, t_list **list, int *len)
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

/*
**	Handles variable expansion inside double quotes
**	
**	@param	s user's input string
**	@param	i the position of the current character on s
**	@param	list a linked list containing the text parsed so far inside double quotes
**	@param	len the total size of all the strings contained in list
**	@return 0 if success < 0 if error
*/
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

/*
**	Handles escape character inside double quotes
**	
**	@param	s user's input string
**	@param	i the position of the escape character on s
**	@param	list a linked list containing the text parsed so far inside double quotes
**	@param	len the total size of all the strings contained in list
**	@return 0 if success < 0 if error
*/
int			ft_quoted_esc(char *s, int *i, t_list **list, int *len)
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
