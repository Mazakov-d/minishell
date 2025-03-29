/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:38:18 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/29 10:30:26 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/builtin.h"
#include "includes/minishell.h"
#include "includes/env.h"

void disp_tab_str(char **str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		printf("mot: %s\n", str[i]);
		i++;
	}
}

void dispData(t_token *token)
{
	t_token *tmp;

	tmp = token;
	while (tmp != NULL)
	{
		disp_tab_str(tmp->cmds);
		tmp = tmp->next;
		if (tmp != NULL)
			printf("fin de phrase ! \n\n");
	}
}

// int main()
// {
// 	int i;
// 	char *line;
// 	t_token *token;

// 	i = 0;
// 	while (i == 0)
// 	{
// 		line = readline(NULL);
// 		if (line)
// 		{
// 			tokenizer(&token, line);
// 			dispData(token);
// 			// printf("i read %s\n", line);
// 		}
// 		else
// 			exit(0);
// 	}
// 	return (0);
// }
