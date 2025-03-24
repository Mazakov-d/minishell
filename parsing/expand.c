/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:21:17 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/24 19:26:50 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*check_var(char	*line, t_data *data)
{
	char	*str;
	int		dq;
	int		sq;
	int		i;

	while (line && line[i])
	{
		is_in_quote(line[i], &sq, &dq);
		if ((line[i] == '$') && !(sq % 2))
			expand_var(line + i, data);
		
	}
}