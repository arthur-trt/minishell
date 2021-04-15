/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:29:21 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/15 18:13:12 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "minishell.h"

void	*ft_malloc(size_t size);
void	init_env_elem(t_env *env);
void	add_env(t_env **env, char *key, char *value);
void	construct_env(t_env **env, char *envp[]);
void	print_env(t_env *env);

char	*search_env(t_env env, char *key);
void	free_env(t_env **env);
void	free_split(char **array);

#endif
