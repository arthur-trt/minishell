/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:32 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/15 19:38:56 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*env;

//int	main(int argc, char *argv[], char **envp)
//{

//	t_lexer *test;
//	char	*input;
//	(void)argc;
//	(void)argv;

//	construct_env(&env, envp);
//	print_env(env);
//	write(1, "PS1 > ", 6);
//	while (get_next_line(0, &input) > 0)
//	{

//		test = lexer(input);
//		#ifdef DEBUG
//			print_lexer(test);
//		#endif
//		free_lexer(&test);
//		free(input);
//		write(1, "PS1 > ", 6);
//	}
//	free(input);

//	return (0);
//}

int		main(int argc, char *argv[], char **envp)
{
	(void)argc;
	char	*exec;

	construct_env(&env, envp);
	print_env(env);
	exec = search_path(env, argv[1]);
	printf("RETURN : %s\n", exec);
	free_env(&env);
	free(exec);
}
