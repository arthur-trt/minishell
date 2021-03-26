/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:29:08 by jcueille          #+#    #+#             */
/*   Updated: 2021/03/26 16:37:53 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_string(char *s, int *i)
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
