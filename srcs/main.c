/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:32 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/05 18:54:45 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char **envp)
{

	t_lexer *test;
	char	*input;
	(void)argc;
	(void)argv;
	(void)envp;

	write(1, "PS1 > ", 6);
	while (get_next_line(0, &input) > 0)
	{

		test = lexer(input);
//		test = lexer(argv[1]);
		#ifdef DEBUG
			print_lexer(test);
		#endif
		free_lexer(&test);
		free(input);
		write(1, "PS1 > ", 6);
	}
	free(input);

	return (0);
}
