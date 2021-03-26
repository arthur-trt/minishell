/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squoted.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:30:48 by jcueille          #+#    #+#             */
/*   Updated: 2021/03/26 16:38:03 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf/includes/libftprintf.h"

char	*ft_single(char *s, int *i)
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
