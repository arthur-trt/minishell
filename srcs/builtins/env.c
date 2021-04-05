/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:57:43 by jcueille          #+#    #+#             */
/*   Updated: 2021/04/05 16:45:46 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern t_env *g_env;

int			ft_env(void)
{
	t_env	*env;

	if (!(env))
		return (-1);
	env = g_env;
	while (env)
	{
		ft_putstr_fd(env->key, 1);
		write(1, "=", 1);
		ft_putstr_fd(env->value, 1);
		ft_putstr_fd("\n", 1);
		env = env->next;
	}
	return (0);
}
