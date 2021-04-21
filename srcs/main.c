/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:32 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 17:29:22 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

t_glob	*g_glob;

int	main(int argc, char *argv[], char **envp)
{

	int		x;
	char	*tmp;

	x = 1;
	g_glob = NULL;
	if(ft_init_gobal())
		return (-1);
	ft_env();
	//signal(SIGINT, c_handler);
	//signal(SIGQUIT, d_handler);
	tmp = NULL;

//	while (x > 0)
//	{
//		ft_prompt();
//		if ((tmp = ft_read(&g_all)) == NULL)
//			x = (g_all.exit->e == -1 ? -1 : 0);
//	}
//	if (x == 0)
//		exit(g_all.exit->e);
//
	free_glob();

	return (0);
}
