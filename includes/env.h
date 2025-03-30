/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:40:29 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/30 17:38:35 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_PARSING_H
# define ENV_PARSING_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "utils.h"

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
char	*ft_strdup(char *str);
t_env	*add_lst(t_env *prev);
t_env	*env_to_struct(char **env);


#endif