/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:53:16 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/03/31 13:53:47 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/env.h"
#include "../includes/builtin.h"

static void init_expand_vars(int *sq, int *dq, char **dup, char *line)
{
	*sq = 0;
	*dq = 0;
	*dup = malloc(sizeof(char) * (ft_strlen(line) + 1));
}

static int skip_var(char *line, int i, int *sq, int *dq)
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

char *expand_null(char *line, int flag, int save, int i)
{
	char *dup;
	int j;
	int dq;
	int sq;

	init_expand_vars(&sq, &dq, &dup, line);
	if (!dup)
		return (NULL);
	j = 0;
	while (line && line[i])
	{
		is_in_quote(line[i], &sq, &dq);
		if (line[i] == '$' && !(sq % 2) && flag == 0)
		{
			save = dq;
			flag++;
			i = skip_var(line, i, &sq, &dq);
		}
		else
			dup[j++] = line[i++];
	}
	dup[j] = '\0';
	return (dup);
}
