/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:21:17 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/31 14:35:59 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/env.h"
#include "../includes/builtin.h"

static int should_expand(char *line, int i, int sq)
{
	return (line[i] == '$' && !(sq % 2) && line[i + 1] && 
		is_alpha(line[i + 1]) && 
		line[i + 1] != ' ' && line[i + 1] != '"' && 
		line[i + 1] != '\'' && !is_digit(line[i + 1]));
}

static int find_var_end(char *line, int i, int *sq, int *dq)
{
	int j;
	int save;

	j = i;
	save = *dq;
	while (line[j] && line[j] != ' ' && !(*sq % 2))
	{
		is_in_quote(line[j], sq, dq);
		if (*dq != save)
			break;
		j++;
	}
	return (j);
}

char *search_var_in_env(char *line, char *var, int end_var, t_env *env)
{
	t_env *ptr;
	char *var_name;
	char *expanded_line;

	var_name = ft_strndup(var + 1, end_var);
	if (!var_name)
	{
		free(line);
		return (NULL);
	}
	ptr = find_in_env(env, var_name);
	if (!ptr)
		expanded_line = expand_null(line, 0, 0);
	else
		expanded_line = expand_line_var(line, ptr->line, 0);
	free(line);
	free(var_name);
	return (expanded_line);
}

char *expand_var(char *line, t_env *env, int i, int j)
{
	int sq;
	int dq;

	dq = 0;
	sq = 0;
	while (line && line[i])
	{
		is_in_quote(line[i], &sq, &dq);
		if (should_expand(line, i, sq))
		{
			j = find_var_end(line, i, &sq, &dq);
			line = search_var_in_env(line, line + i, (j - i - 1), env);
			if (!line)
				return (NULL);
		}
		i++;
	}
	return (line);
}

// char *expand_null(char *line, int flag, int save, int i)
// {
// 	char *dup;
// 	int j;
// 	int dq;
// 	int sq;

// 	sq = 0;
// 	dq = 0;
// 	dup = malloc(sizeof(char) * (ft_strlen(line) + 1));
// 	if (!dup)
// 		return (NULL);
// 	j = 0;
// 	while (line && line[i])
// 	{
// 		is_in_quote(line[i], &sq, &dq);
// 		if (line[i] == '$' && !(sq % 2) && flag == 0)
// 		{
// 			save = dq;
// 			flag++;
// 			while (line[i] && line[i] != ' ' && !(sq % 2))
// 			{
// 				is_in_quote(line[i], &sq, &dq);
// 				if (save != dq)
// 					break;
// 				i++;
// 			}
// 		}
// 		else
// 			dup[j++] = line[i++];
// 	}
// 	dup[j] = '\0';
// 	return (dup);
// }

// char *expand_line_var(char *line, char *var_value, int i_var, int save)
// {
// 	char *s;
// 	int dq;
// 	int sq;
// 	int flag;
// 	int i_line;
// 	int i_s;

// 	while (var_value && var_value[i_var] && var_value[i_var - 1] != '=')
// 		i_var++;
// 	s = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(var_value + i_var) + 2));
// 	if (!s)
// 		return (NULL);
// 	sq = 0;
// 	dq = 0;
// 	flag = 0;
// 	i_line = 0;
// 	i_s = 0;
// 	while (line && line[i_line])
// 	{
// 		is_in_quote(line[i_line], &sq, &dq);
// 		if (line[i_line] == '$' && !(sq % 2) && (flag == 0))
// 		{
// 			save = dq;
// 			flag++;
// 			while (line[i_line] && line[i_line] != ' ' && !(sq % 2))
// 			{
// 				is_in_quote(line[i_line], &sq, &dq);
// 				if (save != dq)
// 					break;
// 				i_line++;
// 			}
// 			while (var_value && var_value[i_var])
// 				s[i_s++] = var_value[i_var++];
// 		}
// 		else
// 			s[i_s++] = line[i_line++];
// 	}
// 	s[i_s] = '\0';
// 	return (s);
// }

// char *expand_var(char *line, t_env *env, int i, int j)
// {
// 	int sq;
// 	int dq;
// 	int save;

// 	dq = 0;
// 	sq = 0;
// 	while (line && line[i])
// 	{
// 		is_in_quote(line[i], &sq, &dq);
// 		if (line[i] == '$' && !(sq % 2) && line[i + 1] && is_alpha(line[i + 1]))
// 		{
// 			if (line[i + 1] != ' ' && line[i + 1] != '"' && line[i + 1] != '\'' && !is_digit(line[i + 1]))
// 			{
// 				j = i;
// 				save = dq;
// 				while (line[j] && line[j] != ' ' && !(sq % 2))
// 				{
// 					is_in_quote(line[j], &sq, &dq);
// 					if (dq != save)
// 						break;
// 					j++;
// 				}
// 				line = search_var_in_env(line, line + i, (j - i - 1), env);
// 				if (!line)
// 					return (NULL);
// 			}
// 		}
// 		i++;
// 	}
// 	return (line);
// }

// // int main(int ac, char **av, char **env)
// // {
// // 	(void)ac;
// // 	(void)av;
// // 	t_data *data = malloc(sizeof(t_data));
// // 	char *line;

// // 	line = ft_strdup("salut $a '$'p ca va");
// // 	data->env = env_to_struct(env);
// // 	printf("%s\n", line);
// // 	ft_export(data->env, "a=salut");
// // 	ft_export(data->env, "b=coucou");
// // 	printf("%s\n", expand_var(line, data, 0, 0));
// // }