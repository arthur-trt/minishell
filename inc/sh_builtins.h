/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:40:55 by jcueille          #+#    #+#             */
/*   Updated: 2021/04/05 18:00:57 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_BUILTINS_H
# define SH_BUILTINS_H

int		ft_export(t_list *cmd);
int		ft_unset(char *s);
int		ft_echo(t_list *cmd);
int		ft_env(void);
int		ft_pwd(void);

int		ft_check_varname(char *s);

#endif