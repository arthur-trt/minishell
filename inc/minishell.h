/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:42 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/26 16:15:25 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libftprintf/includes/libftprintf.h"

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# include "structures.h"
# include "functions.h"
# include "sh_history.h"
# include "sh_input.h"
# include "sh_lexer.h"
# include "sh_constants.h"
# include "sh_utils.h"
# include "exec.h"

#endif
