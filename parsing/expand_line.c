/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:54:11 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/03/31 14:00:39 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/env.h"
#include "../includes/builtin.h"

static int find_var_start(char *var_value, int i_var)
{
	while (var_value && var_value[i_var] && var_value[i_var - 1] != '=')
		i_var++;
	return (i_var);
}

static char *alloc_expanded_str(char *line, char *var_value, int i_var)
{
	char *s;

	s = malloc(sizeof(char) * (ft_strlen(line) + 
		ft_strlen(var_value + i_var) + 2));
	return (s);
}

static int copy_var(char *var_value, char *s, int i_var, int i_s)
{
	while (var_value && var_value[i_var])
		s[i_s++] = var_value[i_var++];
	return (i_s);
}

static int handle_dollar(char *line, int i, int *sq, int *dq)
{
	int save;

	save = *dq;
	while (line[i] && line[i] != ' ' && !(*sq % 2))
	{
		is_in_quote(line[i], sq, dq);
		if (save != *dq)
			break;
		i++;
	}
	return (i);
}

char *expand_line_var(char *line, char *var_value, int i_var)
{
	char *s;
	int i_line;
	int i_s;
	int sq;
	int dq;

	i_var = find_var_start(var_value, i_var);
	s = alloc_expanded_str(line, var_value, i_var);
	if (!s)
		return (NULL);
	sq = 0;
	dq = 0;
	i_line = 0;
	i_s = 0;
	while (line && line[i_line])
	{
		is_in_quote(line[i_line], &sq, &dq);
		if (line[i_line] == '$' && !(sq % 2))
		{
			i_line = handle_dollar(line, i_line, &sq, &dq);
			i_s = copy_var(var_value, s, i_var, i_s);
		}
		else
			s[i_s++] = line[i_line++];
	}
	s[i_s] = '\0';
	return (s);
}
