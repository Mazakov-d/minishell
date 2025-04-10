/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:44:49 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/03/31 15:13:15 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../includes/utils.h"

static int	count_word_minishell(char *str)
{
	int	count;
	int	i;
	int	dq;
	int	sq;

	count = 1;
	i = 0;
	sq = 0;
	dq = 0;
	while (str && str[i])
	{
		is_in_quote(str[i], &sq, &dq);
		if (str[i] == ' ' && !(sq % 2) && !(dq % 2))
		{
			count++;
			while (str[i] && str[i] == ' ')
				i++;
		}
		else
			i++;
	}
	return (count);
}

int	word_len(char *str)
{
	int	i;
	int	dq;
	int	sq;

	i = 0;
	dq = 0;
	sq = 0;
	while (str && str[i])
	{
		is_in_quote(str[i], &sq, &dq);
		if (!(sq % 2) && !(dq % 2) && str[i] == ' ')
			return (i);
		i++;
	}
	return (i);
}

char	*str_dup_minishell(char *s, int *i, int k, int j)
{
	char	*str;
	int		dq;
	int		sq;

	str = malloc(sizeof(char) * (word_len(s + *i) + 1));
	if (!str)
		return (NULL);
	dq = 0;
	sq = 0;
	while (s && s[k])
	{
		is_in_quote(s[k], &sq, &dq);
		if ((s[k] == ' ') && !(sq % 2) && !(dq % 2))
			break ;
		else if (s[k] == '$' && !is_alpha(s[k + 1]) && (!(sq % 2) && !(dq % 2)))
			k += 2;
		else if ((s[k] == '\'' && ((sq % 2) || (!(dq % 2))))
			|| (s[k] == '\"' && ((dq % 2) || (!(sq % 2)))))
			k++;
		else
			str[j++] = s[k++];
	}
	*i = k;
	str[j] = '\0';
	return (str);
}

char	**split_minishell(char *str)
{
	char	**strs;
	int		i;
	int		j;

	i = 0;
	j = 0;
	strs = malloc(sizeof(char *) * (count_word_minishell(str) + 1));
	if (!strs)
		return (NULL);
	while (str && str[i])
	{
		if (str[i] == ' ')
			i++;
		else
		{
			strs[j] = str_dup_minishell(str, &i, i, 0);
			if (!strs[j])
				return (/*free_strs(strs)*/ NULL);
			j++;
		}
	}
	strs[j] = NULL;
	return (strs);
}

// int main()
// {
// 	int i = 0;
// 	char **strs = split_minishell("echo \"    \"  dede\" ghfghjfghfhgfgh");
// 	while (strs[i])
// 	{
// 		printf("%s\n", strs[i]);
// 		i++;
// 	}
// }
