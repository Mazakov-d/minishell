/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:51:21 by yassinefahf       #+#    #+#             */
/*   Updated: 2025/03/24 15:21:55 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int pos_in_str(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int calc_nb_words(char const *s, char *delim)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if ((pos_in_str(delim, s[i])) == -1 && ((pos_in_str(delim, s[i + 1])) >= 0 || s[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

void free_tab_str(char **str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void free_data(t_data **token)
{
	t_data *current;
	t_data *next;

	if (*token)
	{
		current = *token;
		next = NULL;
		while (current != NULL)
		{
			if (current->cmds)
				free_tab_str(current->cmds);
			next = current->next;
			free(current);
			current = next;
		}
		*token = NULL;
	}
}

void alloc_check(void *to_check, t_data *token, int mode)
{
	if (mode == STRUCT)
	{
		if (!token)
			exit(1);
	}
	else
	{
		if (!to_check)
		{
			free_data(token);
			exit(1);
		}
	}
}
int count_pipe(char *line)
{
	int nb;
	int i;

	i = 0;
	nb = 0;
	while (line && line[i])
	{
		if (line[i] == '|')
			nb++;
		i++;
	}
	return (nb);
}

int count_my_str(char *line, t_data *token, int index)
{
	int nb;

	nb = 0;
	while (line[index] == ' ')
		index++;
	while (line[index] != ' ')
		nb++;
}

// int is_double_quote(char *line, int index)
// {
// 	while (line[index])
// 	{
// 		if (line[index] == "\"")
// 			return (DOUBLE_Q);
// 		index++;
// 	}
// 	return (0);
// }

// int is_single_quote(char *line, int index)
// {
// 	while (line[index])
// 	{
// 		if (line[index] == "\'")
// 			return (SINGLE_Q);
// 		index++;
// 	}
// 	return (0);
// }

// int is_double_or_single_quote(char *line)
// {
// 	int i;

// 	i = 0;
// 	while (line && line[i])
// 	{
// 		if (line[i] == '\"')
// 			return (is_double_quote(line, i + 1));
// 		else if (line[i] == '\'')
// 			return (is_single_quote(line, i + 1));
// 		i++;
// 	}
// 	return (0);
// }

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1)
	{
		if (!s2)
			return (0);
		return (-(unsigned char)s2[i]);
	}
	else if (!s2)
		return ((unsigned char)s1[i]);
	while (i < n && s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int is_echo(char *str)
{
	while (str && *str)
	{
		if (*str == 'e')
		{
			if (ft_strncmp(str, "echo", 4) == 0)
				return (1);
		}
		str++;
	}
	return (0);
}