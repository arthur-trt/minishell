/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:48:56 by atrouill          #+#    #+#             */
/*   Updated: 2021/01/29 16:50:46 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(t_env **env)
{
	t_env	*tmp;
	t_env	*next;

	if (env)
	{
		tmp = *env;
		while (tmp)
		{
			next = tmp->next;
			free(tmp);
			tmp = next;
		}
		*env = NULL;
	}
}
