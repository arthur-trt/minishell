/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outfun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:58:45 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/23 20:09:33 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Equivalent to puthcar, use for write special char by termputs
**
**	@param c Char to write on stdout
**
**	@return Return the number written
*/
int	outfun(int c)
{
	return (write(0, &c, 1));
}
