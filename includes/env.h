/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:40:29 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/31 14:28:38 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "utils.h"

/*
** Environment structure
*/
typedef struct s_env
{
	char			*line;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

/*
** Environment utility functions
*/
int		ft_strcmp(char *s1, char *s2);
t_env	*find_in_env(t_env *env, char *str);

/*
** Environment parsing and manipulation
*/
void	*free_new_env(t_env *env);
char	*ft_strdup(char *str);
t_env	*add_lst(t_env *prev);
t_env	*env_to_struct(char **env);

/*
** String modification for environment variables
*/
char	*expand_null(char *line, int flag, int i);
char	*expand_line_var(char *line, char *var_value, int i_var);
char	*search_var_in_env(char *line, char *var, int end_var, t_env *env);

#endif