/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:38:18 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/31 14:24:55 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	is_closed(char *line)
{
	int	dq;
	int	sq;
	int	i;

	i = 0;
	dq = 0;
	sq = 0;
	while (line && line[i])
	{
		is_in_quote(line[i], &sq, &dq);
		i++;
	}
	if ((sq % 2) || (dq % 2))
		return (1);
	return (0);
}

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

void	disp_data(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp != NULL)
	{
		disp_tab_str(tmp->cmds);
		tmp = tmp->next;
		if (tmp != NULL)
			printf("fin de phrase ! \n\n");
	}
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_token	*token;
	t_env	*ev;

	(void)ac;
	(void)av;
	ev = env_to_struct(env);
	while (1)
	{
		line = readline(NULL);
		if (is_closed(line) == 1)
		{
			printf("not closed\n");
		}
		else if (line)
		{
			tokenizer(&token, line, ev);
			disp_data(token);
			// printf("i read %s\n", line);
		}
		else
			exit(0);
	}
	return (0);
}
