/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:33:52 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/03/31 13:59:27 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

/*
** Character manipulation functions
*/
int		is_alpha(char c);
int		is_digit(char c);
int		is_alphanum(char c);
void	is_in_quote(char c, int *sq, int *dq);

/*
** String manipulation functions
*/
size_t	ft_strlen(char *str);
char	*ft_strcat(char *str_a, char *str_b, int flag, int i);
char	*ft_strndup(char *str, int n);

#endif