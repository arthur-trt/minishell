/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:48:56 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/15 19:04:30 by atrouill         ###   ########.fr       */
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
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			tmp = next;
		}
		*env = NULL;
	}
}
