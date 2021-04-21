/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:29:21 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/20 15:05:55 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "minishell.h"

void	*ft_malloc(size_t size);
void	init_env_elem(t_env *env);
void	add_env(t_env **env, char *key, char *value);
int		ft_init_gobal(void);
void	print_env(t_env *env);

char	*search_env(t_env env, char *key);
void	free_glob(void);
void	ft_prompt(void);

void	c_handler(int sigld);
void	d_handler(int sigld);

#endif
