/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:02:42 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/21 18:09:45 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	remove_node(t_env *node)
{
	t_env	*prev;
	t_env	*next;

	prev = node->prev;
	next = node ->next;
	prev->next = next;
	next->prev = prev;
	if (node->line)
		free(node->line);
	free(node);
}

int	ft_unset(t_env *env, char *str)
{
	char	*var_name;
	t_env	*save;

	var_name = get_var_name(str);
	if (!var_name)
		return (1);
	save = find_in_env(env, var_name);
	free(var_name);
	if (save)
		remove_node(save);
	return (0);
}