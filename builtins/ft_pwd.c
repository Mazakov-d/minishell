/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:13:30 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/29 10:25:09 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin.h"

void error_malloc(char *error)
{
	printf("Error : of malloc in %s\n", error);
}

void ft_pwd(void)
{
	char *pwd;
	char *save;
	size_t size;

	pwd = NULL;
	size = 1;
	while (!pwd)
	{
		pwd = malloc(sizeof(char) * size);
		if (!pwd)
			return (error_malloc("ft_pwd, malloc pwd"));
		save = pwd;
		pwd = getcwd(pwd, size);
		if (!pwd)
		{
			free(save);
			size++;
		}
	}
	printf("%s\n", pwd);
	free(pwd);
}
