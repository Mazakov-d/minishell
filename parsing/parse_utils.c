/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:51:21 by yassinefahf       #+#    #+#             */
/*   Updated: 2025/03/31 13:22:56 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	is_in_sq(char c, int *sq)
{
	if (c == '\'')
		*sq = *sq + 1;
}

int	pos_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	free_tab_str(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// void free_data(t_token **token)
// {
// 	t_token *current;
// 	t_token *next;

// 	if (*token)
// 	{
// 		current = *token;
// 		next = NULL;
// 		while (current != NULL)
// 		{
// 			if (current->cmds)
// 				free_tab_str(current->cmds);
// 			next = current->next;
// 			free(current);
// 			current = next;
// 		}
// 		*token = NULL;
// 	}
// }

void	free_token_prev(t_token **token)
{
	t_token	*tmp;
	t_token	*prev;

	if (*token)
	{
		tmp = *token;
		free(tmp);
	}
	tmp = (*token)->prev;
	while (tmp != NULL)
	{
		if (tmp->cmds)
			free_tab_str(tmp->cmds);
		prev = tmp->prev;
		free(tmp);
		tmp = prev;
	}
	*token = NULL;
}

void	alloc_check(void *to_check, t_token *token, int mode)
{
	if (mode == STRUCT)
	{
		if (token->prev && !token)
			free_token_prev(&token);
		if (!token)
			exit(1);
	}
	else if (mode == VOID)
	{
		if (!to_check)
		{
			if (token)
				free_token_prev(&token);
			exit(1);
		}
	}
}

int	count_pipe(char *line)
{
	int	nb;
	int	i;

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1)
	{
		if (!s2)
			return (0);
		return (-(unsigned char)s2[i]);
	}
	else if (!s2)
		return ((unsigned char)s1[i]);
	while (i < n && s1[i] && s2[i]
		&& (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int	is_echo(char *str)
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
