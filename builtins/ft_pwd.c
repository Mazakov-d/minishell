/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:13:30 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/24 19:14:47 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	error_malloc(char *error)
{
	printf("Error : of malloc in %s\n", error);
}

void	ft_pwd(void)
{
	char	*pwd;
	char	*save;
	size_t	size;

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
