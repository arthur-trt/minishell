/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:15:26 by jcueille          #+#    #+#             */
/*   Updated: 2021/05/11 20:22:55 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

int		is_builtin(t_list *cmds)
{
	if (!(ft_strcmp("echo", cmds->content)))
		ft_echo;
	if (!(ft_strcmp("pwd", cmds->content)))
		ft_pwd;
	if (!(ft_strcmp("env", cmds->content)))
		ft_env;
	if (!(ft_strcmp("export", cmds->content)))
		ft_export;
	if (!(ft_strcmp("unset", cmds->content)))
		ft_unset;
	//if (!(ft_strcmp("exit", cmds->content)))
		// ft_exit;
	// if (!(ft_strcmp("cd", cmds->content)))
		// ft_cd;
	else
		ft_exec_path(cmds);
}