/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:40:29 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/21 17:45:45 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_PARSING_H
# define ENV_PARSING_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_env
{
	char			*line;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

/*env_functions.c*/
int		ft_strcmp(char *s1, char *s2);
t_env	*find_in_env(t_env *env, char *str);

/*env_parsing.c*/
void	*free_new_env(t_env *env);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
t_env	*add_lst(t_env *prev);
t_env	*env_to_struct(char **env);

#endif