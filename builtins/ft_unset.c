/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:02:42 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/31 13:18:10 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin.h"

void	remove_node(t_env *node)
{
	t_env	*prev;
	t_env	*next;

	prev = node->prev;
	next = node->next;
	prev->next = next;
	next->prev = prev;
	if (node->line)
		free(node->line);
	free(node);
}

int	ft_unset(t_env *env, char *var_name)
{
	t_env	*save;

	save = find_in_env(env, var_name);
	if (save)
		remove_node(save);
	return (0);
}

// int	main(int ac, char **av, char **env)
// {
// 	char	*str = ft_strdup("asalut");
// 	t_env *ev;

// 	ev = env_to_struct(env);
// 	ft_export(ev, str);
// 	ft_env(ev);
// 	ft_unset(ev, "a");
// 	ft_env(ev);
// 	free_new_env(ev);
// }