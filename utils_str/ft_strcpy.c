/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:03:46 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/03/31 13:19:47 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(char *line)
{
	size_t	i;

	i = 0;
	while (line && line[i])
		i++;
	return (i);
}

char	*ft_strcat(char *str_a, char *str_b, int flag, int i)
{
	char	*str;
	int		j;

	str = malloc(sizeof(char) * (ft_strlen(str_a) + ft_strlen(str_b) + 1));
	if (!str)
	{
		if (flag == 1 && str_b)
			free(str_b);
		return (NULL);
	}
	while (str_a && str_a[i])
	{
		str[i] = str_a[i];
		i++;
	}
	j = 0;
	while (str_b && str_b[j])
	{
		str[i + j] = str_b[j];
		j++;
	}
	str[i + j] = 0;
	if (flag == 1 && str_b)
		free(str_b);
	return (str);
}

char	*ft_strndup(char *str, int n)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	while (str && str[i] && i < n)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
