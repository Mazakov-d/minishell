/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:16:57 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/21 17:44:02 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
