/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:16:30 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/21 17:58:07 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	add_lst_str(t_env *prev, char *var)
{
	t_env	*new_node;
	t_env	*next;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (1);
	next = prev->next;
	new_node->prev = prev;
	new_node->next = next;
	prev->next = new_node;
	next->prev = new_node;
	new_node->line = var;
	return (0);
}

char	*get_var_name(char *str)
{
	char	*var;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str && str[i] && str[i] != '=')
		i++;
	if (!str[i])
		return (NULL);
	var = malloc(sizeof(char) * (i + 2));
	if (!var)
		return (NULL);
	while (j <= i)
	{
		var[j] = str[j];
		j++;
	}
	var[j] = 0;
	return (var);
}

void	modify_line(t_env *env, char *new_line)
{
	free(env->line);
	env->line = new_line;
}

int	ft_export(t_env *env, char *new_var)
{
	char	*var_name;
	t_env	*save;

	if (!new_var)
		return (0);
	var_name = get_var_name(new_var);
	if (!var_name)
		return (1);
	save = find_in_env(env, var_name);
	free(var_name);
	if (!save)
	{
		if (add_lst_str(env, new_var) == 1)
			return (1);
	}
	else
		modify_line(save, new_var);
	return (0);
}
