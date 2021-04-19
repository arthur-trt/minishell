/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:48:45 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/19 20:38:43 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern	t_glob *g_glob;
extern char **environ;


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

static void	construct_env(t_env **env, char *envp[])
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

int	ft_init_gobal(void)
{
	if(!(g_glob = malloc(sizeof(t_glob *))))
	{
		ft_putstr_fd("malloc error.\n", 2);
		return (-1);
	}
	construct_env(&g_glob->env, environ);
	return (0);
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
