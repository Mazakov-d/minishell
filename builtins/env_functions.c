/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:19:12 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/31 13:19:00 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/env.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s2)
		return (0);
	while (s1 && s2 && s1[i] == s2[i])
		i++;
	if (!s1[i] && !s2[i])
		return (2);
	if (!s2[i])
		return (1);
	return (0);
}

t_env	*find_in_env(t_env *env, char *str)
{
	t_env	*save;

	save = env;
	while (save->prev)
		save = save->prev;
	while (save->next)
	{
		if (ft_strcmp(save->line, str))
			return (save);
		save = save->next;
	}
	return (NULL);
}
