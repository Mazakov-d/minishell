/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:38:18 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/23 16:38:10 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	int i;
	char *line;
	t_data token;

	i = 0;
	while (i == 0)
	{
		line = readline(NULL);
		if (line)
		{
			tokenizer(&token, line);
			printf("i read %s\n", line);
		}
		else
			exit(0);
	}
	return (0);
}
