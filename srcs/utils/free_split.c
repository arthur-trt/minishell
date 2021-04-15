/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:55:54 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/15 18:12:58 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Free a char array obtain with ft_split
**
**	@param array Array to split
*/
void	free_split(char **array)
{
	int	i;

	i = 0;
	while(array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
