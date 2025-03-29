/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:16:57 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/29 10:24:21 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/env.h"

void ft_env(t_env *env)
{
	while (env->prev)
		env = env->prev;
	while (env->next)
	{
		printf("%s\n", env->line);
		env = env->next;
	}
}
