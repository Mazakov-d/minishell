/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:07:04 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/28 16:18:16 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "parsing/minishell.h"

void	disp_tab_str(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		printf("mot: %s\n", str[i]);
		i++;
	}
}

void	dispData(t_data *tmp)
{
	// t_data *tmp;

	// tmp = token;
	disp_tab_str(tmp->cmds);
	printf("fin de phrase ! \n");
}

void	append(t_data **token, char **av, int ac)
{
	t_data	*tmp;
	int		i;

	i = 1;
	*token = ft_calloc(1, sizeof(t_data));
	tmp = *token;
	// tmp = (t_data *)ft_calloc(4, sizeof(t_data));
	// tmp->next = (t_data *)ft_calloc(4, sizeof(t_data));
	// tmp->next->next = (t_data *)ft_calloc(4, sizeof(t_data));
	while (i < ac)
	{
		tmp->cmds = pipe_split(av[i], " ");
		dispData(tmp);
		tmp->next = ft_calloc(1, sizeof(t_data));
		tmp->next->prev = tmp;
		tmp = tmp->next;
		i++;
	}
}

void	reset_head(t_data **data, char **av)
{
	// t_data	*tmp;
	t_data	*new;

	new = (t_data *)ft_calloc(4, sizeof(t_data));
	new->cmds = pipe_split(av[3], " ");
	// tmp = *data;
	*data = new;
}

void	init_tok(t_data **token)
{
	*token = (t_data *)ft_calloc(1, sizeof(t_data));
	(*token)->next = (t_data *)ft_calloc(1, sizeof(t_data));
	(*token)->next->next = (t_data *)ft_calloc(1, sizeof(t_data));
}

// int main(int ac, char **av)
// {
// 	t_data	*token;

// 	// token = ft_calloc(4, sizeof(t_data));
// 	// token->next = (t_data *)ft_calloc(4, sizeof(t_data));
// 	// token->next->next = (t_data *)ft_calloc(4, sizeof(t_data));
// 	// init_tok(&token);
// 	append(&token, av, ac);
// 	reset_head(&token, av);
// 	printf("\n\n");
// 	dispData(token);
// }
