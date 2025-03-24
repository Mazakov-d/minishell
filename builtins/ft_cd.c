/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:13:54 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/24 16:41:04 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	*ft_strcat(char *str_a, char *str_b)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (ft_strlen(str_a) + ft_strlen(str_b) + 1));
	if (!str)
		return (NULL);
	i = 0;
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
	if (str_b)
		free(str_b);
	return (str);
}

char	*get_pwd(char *prefix)
{
	size_t	size;
	char	*pwd;
	char	*save;

	pwd = NULL;
	save = NULL;
	size = 0;
	while (!pwd)
	{
		pwd = malloc(sizeof(char) * size);
		if (!pwd)
			return (NULL);
		save = pwd;
		pwd = getcwd(pwd, size);
		if (!pwd)
		{
			free(save);
			size++;
		}
	}
	pwd = ft_strcat(prefix, pwd);
	return (pwd);
}

void	put_pwd(t_env *env, char **pwd)
{
	char	*save;

	if (!env)
		add_lst_str(env, *pwd);
	else
	{
		save = env->line;
		env->line = *pwd;
		free(save);
	}
}

int	get_home(t_env *env, char **arg)
{
	t_env	*ptr;

	ptr = find_in_env(env, "HOME");
	if (!ptr)
	{
		printf("cd: HOME not set\n");
		return (1);
	}
	*arg = ft_strcat(env->line + 4, NULL);
	if (!*arg)
		return (2);
	return (0);
}

int	ft_cd(t_env *env, char *arg)
{
	char	*old_pwd;
	char	*new_pwd;
	t_env	*env_pwd;

	if (!arg && get_home(env, &arg))
		return (1);
	old_pwd = get_pwd("OLDPWD=");
	if (!old_pwd)
		return (2);
	printf("%s\n", old_pwd);
	if (chdir(arg) == -1)
	{
		free(old_pwd);
		printf("cd: %s: No such file or directory\n", arg);
		return (1);
	}
	env_pwd = find_in_env(env, "PWD=");
	new_pwd = get_pwd("PWD=");
	if (!new_pwd)
	{
		free(old_pwd);
		return (2);
	}
	put_pwd(env, &new_pwd);
	env_pwd = find_in_env(env, "OLDPWD=");
	put_pwd(env, &old_pwd);
	return (0);
}

int main(int ac, char **av, char **env)
{
	t_env *e;

	e = env_to_struct(env);
	// ft_pwd();
	// ft_env(e);
	if (ft_cd(e, ".."))
		printf("OKcd\n");
	// ft_pwd();
	// ft_env(e);
}