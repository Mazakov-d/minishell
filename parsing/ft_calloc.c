/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:38:23 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/25 14:39:20 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	size_t	i;

	if (size != 0 && nmemb > __SIZE_MAX__ / size)
		return (NULL);
	dest = malloc((nmemb * size) * sizeof(void));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		*(unsigned char *)(dest + i) = 0;
		i++;
	}
	return (dest);
}