/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:45:53 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/31 14:25:18 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "env.h"

/*
** Echo command
*/
int		is_n(char *flag);
void	ft_echo(char **str);

/*
** Environment commands
*/
void	ft_env(t_env *env);
int		add_lst_str(t_env *prev, char *var);
char	*get_var_name(char *str);
void	modify_line(t_env *env, char *new_line);
int		ft_export(t_env *env, char *new_var);

/*
** Directory and file commands
*/
void	ft_pwd(void);
void	error_malloc(char *error);
char	*get_pwd(char *prefix);
void	put_pwd(t_env *env, char **pwd, int i);
int		get_home(t_env *env, char **arg);
int		ft_cd(t_env *env, char *arg);

/*
** Environment manipulation commands
*/
void	remove_node(t_env *node);
int		ft_unset(t_env *env, char *str);

#endif