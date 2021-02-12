/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:48:45 by atrouill          #+#    #+#             */
/*   Updated: 2021/02/06 20:26:09 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env_elem(t_env *env)
{
	env->key = NULL;
	env->value = NULL;
	env->next = NULL;
}

void	add_env(t_env **env, char *key, char *value)
{
	t_env	*new;
	t_env	*tmp;

	if (!(new = ft_malloc(sizeof(t_env))))
		exit(EXIT_FAILURE);
	init_env_elem(new);
	new->key = key;
	new->value = value;
	if ((*env) == NULL)
	{
		new->next = (*env);
		(*env) = NULL;
	}
	else
	{
		tmp = (*env);
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
}

void	construct_env(t_env **env, char *envp[])
{
	char	**tmp;
	int		i;

	i = 0;
	while (envp[i])
	{
		tmp = ft_split(envp[i], '=');
		add_env(env, tmp[0], tmp[1]);
		free(tmp[0]);
		free(tmp[1]);
		free(tmp);
		i++;
	}
}

void	print_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp != NULL)
	{
		printf("key : %s\n", tmp->key);
		printf("value : %s\n\n", tmp->value);
		tmp = tmp->next;
	}
}
