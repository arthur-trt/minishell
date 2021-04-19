/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:57:43 by jcueille          #+#    #+#             */
/*   Updated: 2021/04/19 20:46:06 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern t_glob *g_glob;

int			ft_env(void)
{
	t_env	*env;

	if (!(env))
		return (-1);
	env = g_glob->env;
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
