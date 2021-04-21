/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:48:45 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 17:28:51 by jcueille         ###   ########.fr       */
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

/*
**	Creates basic environment if env = NULL
**
**	@return 0 on success -1 if malloc error
*/
static int ft_empty_env(void)
{
	char *cwd;
	char	buf[4096];

	cwd = getcwd(buf, 4096);
	add_env(&g_glob->env, "PWD", cwd);
	add_env(&g_glob->env, "SHLVL", ft_strdup("0"));
	return (0);
}

int	ft_init_gobal(void)
{
	//g_glob->env = NULL;
	write(1, "1", 1);
	if (environ)
		construct_env(&g_glob->env, environ);
	else
		ft_empty_env();
	return (0);
}
