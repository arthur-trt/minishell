/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:48:44 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/15 12:07:18 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

# include <dirent.h>

char	*scan_dir(char *path, char *exec_name);
char	*search_path(t_env *env, char *exec_name);

#endif
