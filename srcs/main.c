/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:32 by atrouill          #+#    #+#             */
/*   Updated: 2021/01/11 19:03:40 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char **envp)
{
	char	*buffer;

	(void)argc;
	(void)argv;
	(void)envp;
	buffer = NULL;
	ft_putstr_fd("minishell $> ", 1);
	while(get_next_line(0, &buffer) > 0)
	{
		printf("cmd = %s\n", buffer);
		ft_putstr_fd("minishell $> ", 1);
	}
	printf("Bye.\n");
	return (0);
}
