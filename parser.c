/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:12:48 by jcueille          #+#    #+#             */
/*   Updated: 2021/03/21 13:42:51 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./srcs/libft/libft.h"
#include "./srcs/Minishell.h"



void	ft_new_env(void)
{
	t_env *tmp;

	g_env = malloc(sizeof(t_env));
	g_env->key = ft_strdup("VAR");
	g_env->value = ft_strdup("VALUE");
	tmp = malloc(sizeof(t_env));
	g_env->next = tmp;
	tmp->key = ft_strdup("VARZ");
	tmp->value = ft_strdup("VALUZ");
	tmp->next = NULL;
}

/*
**	REMOVE A SINGLE CHAR FROM A STRING
*/

static void	ft_remove_char(char *s, int i)
{
	char	*res;
	int		j;

	if (!(res = malloc(ft_strlen(s) * sizeof(char))))
		return ;
	j = -1;
	while (++j < i)
		res[j] = s[j];
	i = j;
	while (s[++j])
	{
		res[i] = s[j];
		i++;
	}
	res[j - 1] = '\0';
	free(s);
	s = ft_strdup(res);
	free(res);
}

/*
**	CHECKS IF VAR BRACKETS ARE CLOSED
*/

static int	ft_bracket_check(char *s, int i)
{
	while (s[i])
	{
		if (s[i] == '}')
			return (1);
		i++;
	}
	printf("ERROR: BRACKET MISSING\n");
	return (0);
}

/*
**	STRING SANS QUOTES
*/

static char	*ft_string(char *s, int *i)
{
	int		j;
	char	*res;

	j = *i;
	while (s[j] && s[j] != ' ' && s[j] != '\"' && s[j] != '\'' && s[j] != '$')
	{
		if (s[j] == '\\')
		{
			ft_remove_char(s, j);
			j++;
		}
		j++;
	}
	res = ft_substr(s, *i, j - *i);
	(*i) = j - 1;
	return (res);
}

static char	*ft_single(char *s, int *i)
{
	int		j;
	char	*res;

	j = (*i) + 1;
	while (s[j] && s[j] != '\'')
		j++;
	res = ft_substr(s, (*i) + 1, j - (*i + 1));
	(*i) = j;
	return (res);
}

/*
**	RETRIEVE VAR VALUE
*/

static char	*ft_search_var(char *s, int *inc, int flag, int *i)
{
	int		k;
	int		j;
	t_env	*tmp;
	char	*name;
	char	*res;

	k = *i + 1;
	(*inc) = 0;
	tmp = g_env;
	res = NULL;
	if (!(s[k]))
		return (res);
	if (s[k] == '{')
	{
		if (!(ft_bracket_check(s, k)))
			return (res);
		(*inc) += 2;
		k++;
	}
	j = k;
	while (s[j] && s[j] != ' ' && s[j] != '}')
		j++;
	if (j - k == 0)
		return (NULL);
	name = ft_substr(s, k, j - k);
	while (tmp)
	{
		if (ft_strncmp(tmp->key, name, ft_strlen(tmp->key)) == 0)
			res = ft_strdup(tmp->value);
		/*int l = ft_strncmp(tmp->key, name, ft_strlen(tmp->key));
		**	if (l == 0)
		**	res = ft_strdup(tmp->value);
		*/
		tmp = tmp->next;
	}
	*inc += ft_strlen(name);
	free(name);
	if (s[++j] && flag == 1)
	{
		if (res)
			name = ft_strjoin(res, &s[j]);
		else
			name = ft_strdup(&s[j]);
	}
	else
		return (res);
	free(res);
	return (name);
}

/*
**	DOLLAR DANS QUOTES
*/

// static char	*ft_dollar(char *s, int *i, int *j)
// {
// 	char	*tmp;
// 	char	*res;
// 	int		inc;

// 	if (!(s[*j + 1]))
// 	{
// 		s[*j] = '\0';
// 		(*j)--;
// 		return (s);
// 	}
// 	if (s[*j + 1] == '\"')
// 	{
// 		ft_remove_char(s, *j);
// 		(*j)--;
// 		return (s);
// 	}
// 	res = ft_search_var(s, &inc, 1, j);
// 	s[*j] = '\0';
// 	if (inc > 0)
// 		*j = inc - 1;
// 	if (*j > 0 && s[*j - 1])
// 	{
// 		tmp = ft_strjoin(s, res);
// 		free(s);
// 		free(res);
// 		return (tmp);
// 	}
// 	free(s);
// 	return (res);
// }

// static int	ft_quoted_esc(char *s, int *j, int *k)
// {
// 	if (s[*j + 1] == '\\' || s[*j + 1] == '\"' || s[*j + 1] == '$')
// 	{
// 		ft_remove_char(s, *j);
// 		(*j)++;
// 		(*k)++;
// 	}

// }

/*
**	DOUBLE QUOTES
*/

// static char	*ft_double(char *s, int *i)
// {
// 	int		j;
// 	int		k;
// 	int		vars;
// 	char	*s_copy;
// 	char	*res;

// 	j = *i + 1;
// 	k = 0;
// 	vars = 0;
// 	if (!(s[j]))
// 		return (NULL);
// 	s_copy = ft_strdup(&s[j]);
// 	j = 0;
// 	while (s_copy[j] && s_copy[j] != '\"')
// 	{
// 		if (s_copy[j] == '\\')
// 			ft_quoted_esc(s, &j, &k);
// 		if (s_copy[j] ==  '$')
// 		{	
// 			s_copy = ft_dollar(s_copy, i, &j);
// 			vars++;
// 		}
// 		j++;
// 	}
// 	if (s_copy[j] == '\0')
// 		printf("ERROR: DOUBLE QUOTE NOT CLSOED\n");
// 	s_copy[j] = '\0';
// 	(*i) += j + 2 + vars;
// 	return (s_copy);
// }

void	ft_listclear(t_list **lst)
{
	t_list *nxt;
	t_list *tmp;

	tmp = *lst;
	while (tmp)
	{
		nxt = (tmp)->next;
		free(tmp->content);
		tmp->content = NULL;
		free(tmp);
		tmp = nxt;
	}
	*lst = NULL;
}

void	ft_quoted_str(char *s, int *i, t_list **list, int *len)
{
	int		j;
	char	*res;
	t_list	*tmp;

	j = *i;
	while (s[j] && s[j] != '\"' && s[j] != '\\' && s[j] != '$')
		j++;

	res = ft_substr(s, *i, j - *i);
	tmp = ft_lstnew(res);
	ft_lstadd_back(list, tmp);
	*i = j - 1;
	(*len) += ft_strlen(res);
}

void ft_dollar(char *s, int *i, t_list **list, int *len)
{
	char	*res;
	int		inc;
	t_list	*tmp;

	if (!(res = ft_search_var(s, &inc, 0, i)))
		return ;
	tmp = ft_lstnew(res);
	ft_lstadd_back(list, tmp);
	(*i) += inc;
	(*len) += ft_strlen(res);
}

static void	ft_quoted_esc(char *s, int *i, t_list **list, int *len)
{
	char	*res;
	t_list	*tmp;

	(*i)++;
	if (!(s[*i]))
		return ;
	res = ft_substr(s, *i, 1);
	tmp = ft_lstnew(res);
	ft_lstadd_back(list, tmp);
	(*len) += ft_strlen(res);
}

char	*ft_concat(t_list *list, int len)
{
	t_list	*tmp;
	char	*res;
	int		i;
	int		j;

	i = 0;
	res = ft_calloc(len + 1, sizeof(char));
	//res[len + 1] = '\0';
	tmp = list;
	while (tmp)
	{
		j = 0;
		while (tmp->content[j])
		{
			res[i] = tmp->content[j];
			i++;
			j++;
		}
		tmp = tmp->next;
	}
	ft_listclear(&list);
	return (res);
}

char 	*ft_double(char *s, int *i)
{
	t_list	*list;
	char	*res;
	int		len;

	len = 0;
	list = NULL;
	res = NULL;
	(*i)++;
	while (s[*i] && s[*i] != '\"')
	{
		if (s[*i] == '$')
			ft_dollar(s, i, &list, &len);
		else if (s[*i] == '\\')
			ft_quoted_esc(s, i, &list, &len);
		else
			ft_quoted_str(s, i, &list, &len);
		(*i)++;	
	}
	if (list)
		res = ft_concat(list, len);
	return (res);
}

/*
**	APPLY FT ACCORDING TO QUOTES OR NOT
*/

char		*ft_apply(char *s, int *i, char *(*f)(char *s, int *i), char *res)
{
	char	*tmp;
	char	*tmp_bis;

	tmp = (*f)(s, i);
	if (!(res))
		tmp_bis = ft_strdup(tmp);
	else
		tmp_bis = ft_strjoin(res, tmp);
	free(res);
	res = NULL;
	free(tmp);
	return (tmp_bis);
}

char	*ft_apply_var(char *s, int *i, char *res)
{
	char	*tmp;
	char	*tmp_bis;
	int		inc;

	tmp_bis = NULL;
	tmp_bis = ft_search_var(s, &inc, 0, i);
	(*i) += inc;
	if (!(tmp_bis))
		return (res);
	if (res)
		tmp = ft_strjoin(res, tmp_bis);
	else
	{
		free(res);
		return (tmp_bis);
	}
	free(res);
	return (tmp);
}

//ADDS STR TO COMMANDS LIST WHEN SPLITTING SPACE IS REACHED

void		ft_empty_buffer(char *s, t_list **command)
{
	t_list	*tmp;
	char	*copy;

	if (!(s))
		return ;
	copy = ft_strdup(s);
	tmp = ft_lstnew(copy);
	ft_lstadd_back(command, tmp);
}

t_list		*ft_parse(char *s)
{
	t_list	*command;
	char	*res;
	int		i;

	i = -1;
	res = NULL;
	command = NULL;
	while (s[++i])
	{
		if (s[i] == '\"')
			res = ft_apply(s, &i, &ft_double, res);
		else if (s[i] == ' ')
		{
			ft_empty_buffer(res, &command);
			free(res);
			res = NULL;
		}
		else if (s[i] == '\'')
			res = ft_apply(s, &i, &ft_single, res);
		else if (s[i] == '$')
			res = ft_apply_var(s, &i, res);
		else
			res = ft_apply(s, &i, &ft_string, res);
	}
	if (res)
		ft_empty_buffer(res, &command);
	while (command)
	{
		printf("S IS %s\n", command->content);
		command = command->next;
	}
	return (command);
}

int	main(void)
{
	char *s;

	ft_new_env();
/*	
**	s = ft_strdup("\"${VAR}\" \"\'lol\'\" ${VR} mdr");
*/
	s = ft_strdup("\"\'prout porout \\\\ $\'\"$ $VAR tamere la pute\"test 3 $\" \'\"lol\\n\"\'");
	ft_parse(s);
	printf("%s\n", s);
	free(s);
	//ft_env();
	//ft_pwd();
	return (0);
}
