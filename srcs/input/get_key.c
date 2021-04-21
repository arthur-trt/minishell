/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:04:05 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 17:28:53 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	convert_code(char *key)
{
	if (ft_memcmp(KEY_CODE_UP, key, 4) == 0)
		return (KEY_UP);
	if (ft_memcmp(KEY_CODE_DOWN, key, 4) == 0)
		return (KEY_DOWN);
	if (ft_memcmp(KEY_CODE_LEFT, key, 4) == 0)
		return (KEY_LEFT);
	if (ft_memcmp(KEY_CODE_RIGHT, key, 4) == 0)
		return (KEY_RIGHT);
	if (ft_memcmp(KEY_CODE_DEL, key, 4) == 0)
		return (KEY_DC);
	return (key[0]);
}

/*
**	Get the code of the current key.
**	Transforms the special codes into a code understandable by curses.h
**
**	@return Key code entered by user
*/
int		get_key(void)
{
	char	*key_pressed;
	int		key;

	key_pressed = ft_str_malloc(4);
	if (key_pressed == NULL)
		return (-1);
	read(0, key_pressed, 1);
	if (*key_pressed == '\x1b')
	{
		read(0, (key_pressed + 1), 2);
	}
	key = convert_code(key_pressed);
	free(key_pressed);
	return (key);
}
