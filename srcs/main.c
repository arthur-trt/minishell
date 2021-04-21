/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:32 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/19 20:44:03 by atrouill         ###   ########.fr       */
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

#include <string.h>

//static void print_escape_sequence(char *str)
//{
//        unsigned i = 0;

//        while (str[i] != '\0')
//        {
//                if (str[i] == '\x1b')
//                        printf("ESC");
//                else
//                        putchar(str[i]);

//                ++i;
//        }

//        putchar('\n');
//}

int		main(int argc, char *argv[], char **envp)
{
//	char *buffer = (char *) malloc(2048);

	(void)argc;
	(void)argv;
	(void)envp;
	char	*test;

	test = input();
	printf("\nRETURN : %s\n", test);
	free(test);
//	ft_bzero(buffer, 2048);
	//set_term_raw_mode();
	//test = tgetstr("im", NULL);
	//print_escape_sequence(test);
	//set_term_default_mode();
	return (0);

}
