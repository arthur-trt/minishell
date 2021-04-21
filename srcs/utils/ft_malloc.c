/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:24:17 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/17 20:28:12 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_malloc(size_t size)
{
	char	*ret;

	ret = malloc(size);
	if (ret == NULL)
	{
		ft_printf("Malloc failed.");
		exit (1);
	}
	return (ret);
}

char	*ft_str_malloc(size_t size)
{
	char			*str;
	unsigned int	i;

	if ((str = (char *)malloc(sizeof(*str) * size + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	};
	return (str);
}
