/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:19:12 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/24 15:19:51 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
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
	t_env	*rtn;
	t_env	*save;

	save = env;
	while (env->prev)
		env = env->prev;
	while (env->next)
	{
		if (ft_strcmp(env->line, str))
		{
			rtn = env;
			env = save;
			return (rtn);
		}
		env = env->next;
	}
	return (NULL);
}
