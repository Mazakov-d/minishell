/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:16:57 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/31 13:18:22 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/env.h"

void	ft_env(t_env *env)
{
	while (env->prev)
		env = env->prev;
	while (env->next)
	{
		printf("%s\n", env->line);
		env = env->next;
	}
}
