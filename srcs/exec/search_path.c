/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:39:35 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/15 20:24:33 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*clean_path(char *path)
{
	int		len;
	char	*tmp;

	len = ft_strlen(path);
	if (path[len -1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		free(path);
		return (tmp);
	}
	return (path);
}

char	*scan_dir(char *path, char *exec_name)
{
	DIR				*folder;
	struct dirent	*entry;

	folder = opendir(path);
	while ((entry = readdir(folder)))
	{
		if (ft_strcmp(exec_name, entry->d_name) == 0)
		{
			free(folder);
			return (ft_strjoin(path, exec_name));
		}
	}
	free(folder);
	return (NULL);
}

/*
**	Search exec in all PATH folder and in current dir
**
**	@param env Linked list representation of Env
**	@param exec_name Exec to search in path
**
**	@return Return path + exec_name
*/
char	*search_path(t_env *env, char *exec_name)
{
	char	*path;
	int		i;
	char	**tmp;
	char	*test;

	path = search_env(*env, "PATH");
	tmp = ft_split(path, ':');
	i = 0;
	while (tmp[i] != NULL)
	{
		tmp[i] = clean_path(tmp[i]);
		test = scan_dir(tmp[i], exec_name);
		if (test != NULL)
		{
			free_split(tmp);
			return (test);
		}
		i++;
	}
	free_split(tmp);
	test = scan_dir("./", exec_name);
	if (test != NULL)
		return (test);
	return (NULL);
}
