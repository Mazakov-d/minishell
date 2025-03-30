/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:45:53 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/30 17:39:26 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "env.h"

/*ft_echo.c*/
int		is_n(char *flag);
void	ft_echo(char **str);

/*ft_env.c*/
void	ft_env(t_env *env);

/*ft_export.c*/
int		add_lst_str(t_env *prev, char *var);
char	*get_var_name(char *str);
void	modify_line(t_env *env, char *new_line);
int		ft_export(t_env *env, char *new_var);

/*ft_exit.c*/

/*ft_pwd.c*/
void	ft_pwd();

/*ft_cd.c*/

/*ft_unset.c*/
void	remove_node(t_env *node);
int		ft_unset(t_env *env, char *str);

#endif