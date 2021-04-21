/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:09:43 by jcueille          #+#    #+#             */
/*   Updated: 2021/04/20 15:07:39 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/includes/libft.h"
#include "../inc/minishell.h"

extern t_glob *g_glob;

void	c_handler(int sigld)
{
	ft_putstr_fd("\n", 2);
	exit(sigld);
}

void	d_handler(int sigld)
{
	(void)sigld;
	if (g_all.prog == 1)
	{
		g_all.err = 131;
		kill(g_pid, SIGQUIT);
		ft_putendl_fd("Quit (core dumped)", 1);
	}
	else
		ft_putstr_fd("\b \b\b \b", 1);
}