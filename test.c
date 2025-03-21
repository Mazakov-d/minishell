/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:07:04 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/21 12:03:39 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*test for the function getcwd*/
char	*ft_getcwd()
{
	char	 *str;
	size_t	size;
	char	*save;

	str = NULL;
	size = 1;
	while(!str)
	{
		str = malloc(sizeof(char) * size);
		if (!str)
			return (NULL);
		save = str;
		str = getcwd(str, size);
		if (!str)
		{
			free(save);
			size++;
		}
	}
	printf("The path is : %s\n", str);
	printf("This is the size : %zu\n", size);
	return (str);
}

/*test for the function chdir*/
int	ft_chdir(char *new_path)
{
	char	*actual_path;
	int		rtrn;

	actual_path = ft_getcwd();
	printf("actual path : %s\n", actual_path);
	free(actual_path);
	rtrn = chdir(new_path);
	printf("return value of chdir : %d\n", rtrn);
	actual_path = ft_getcwd();
	printf("new path : %s\n", actual_path);
	free(actual_path);
	return (0);
}

int main()
{
	ft_chdir("");
}