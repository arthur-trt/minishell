
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:27:21 by jcueille          #+#    #+#             */
/*   Updated: 2021/04/16 17:05:48 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

static char	*get_username(void)
{
	char	*username;

	username = getenv("USER");
	if (username == NULL)
		username = ft_strdup("username");
	return (username);
}

static char *get_home(void)
{
	char	*home;

	home = getenv("HOME");
	return (home);
}

void		ft_prompt(void)
{
	char	cwd_buffer[MAX_CMD_LINE];
	char	*cwd;
	char	*path;

	ft_bzero(cwd_buffer, MAX_CMD_LINE);
	cwd = getcwd(cwd_buffer, MAX_CMD_LINE);
	if (ft_strcmp(cwd, get_home()) == 0)
	{
		free(cwd);
		cwd = ft_strdup("~");
	}
	ft_putstr_fd("\e[1;32m", 1);
	ft_putstr_fd(get_username(), 1);
	ft_putstr_fd("@", 1);
	ft_putstr_fd(cwd, 1);
	ft_putstr_fd(" > \e[0m", 1);

}

