/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:32 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/24 16:18:26 by atrouill         ###   ########.fr       */
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



int		main(int argc, char *argv[], char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	char	*test;

	test = input();
	printf("\nRETURN : %s\n", test);
	free(test);
	return (0);

}

//int	main(void)
//{
//	t_size	win;
//	t_size	cursor;

//	set_term_raw_mode();
//	outfun_str("PROMTP > ");
//	win = get_win_size();
//	cursor = get_current_cursor_position();
//	set_term_default_mode();
//	printf("win :\n\tcol : %zu\n\trow : %zu\n\n", win.col, win.row);
//	printf
//	("cursor :\n\tcol : %zu\n\trow : %zu\n\n", cursor.col, cursor.row);
//	return (0);
//}

//int	main(void)
//{
//	set_term_raw_mode();
//	get_key();
//	set_term_default_mode();
//	return (0);
//}
