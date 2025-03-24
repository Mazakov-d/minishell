/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:21:17 by dmazari           #+#    #+#             */
/*   Updated: 2025/03/24 20:06:22 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



char	*expand_null(char *line, int flag, int save, int i)
{
	char	*dup;
	int		j;
	int		dq;
	int		sq;

	sq = 0;
	dq = 0;
	dup = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!dup)
		return (NULL);
	j = 0;
	while (line && line[i])
	{
		is_in_quote(line[i], &sq, &dq);
		if (line[i] == '$' && !(sq % 2) && flag == 0)
		{
			save = dq;
			flag++;
			while (line[i] && line[i] != ' ' && save == dq && !(sq % 2))
			{
				is_in_quote(line[i], &sq, &dq);
				i++;
			}
		}
		else
			dup[j++] = line[i++];
	}
	dup[j] == 0;
	return (dup)
}

char	*expanded_line_var(char *line, char *var_value, int i, int save)
{
	char	*s;
	int		dq;
	int		sq;
	int		flag;
	int		j;
	int		k;

	while (var_value && var_value[i] && var_value[i - 1] != '=')
		i++;
	s = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(var_value + i) + 1));
	if (!s)
		return (NULL);
	i = 0;
	sq = 0;
	dq = 0;
	flag = 0;
	j = 0;
	k = 0;
	while (line && line[i])
	{
		is_in_quote(line[i], &sq, &dq);
		if (line[i] == '$' && !(sq % 2) && (flag == 0))
		{
			save = dq;
			flag++;
			while (line[i] && line[i] != ' ' && save == dq && !(sq % 2))
				is_in_quote(line[i++], &sq, &dq);
			while (var_value && var_value[j])
				s[k++] == var_value[j++];
		}
		else
			s[k++] = line[i++];
	}
	s[k] = 0;
	return (s);
}


char	*ft_strndup(char *str, int n)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char) * n + 1);
	if (!dup)
		return (NULL);
	while (str && str[i] && i < n)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*search_var_in_env(char *line, char *var, int end_var, t_env *env)
{
	t_env	*ptr;
	char	*var_name;
	char	*expanded_line;
	int		i;

	var_name = ft_strndup(var, end_var);
	if (!var_name)
		return (NULL);
	ptr = find_in_env(env, var_name);
	if (!ptr)
		expanded_line = expand_null(line, 0, 0, 0);
	else
		expanded_line = expand_line_var(line, ptr->line, 0);
	free(line);
	free(var_name);
	return (expanded_line);
}

char	*expand_var(char *line, t_data *data, int i, int j)
{
	char	*expanded_line;
	int		sq;
	int		dq;
	int		save;

	dq = 0;
	sq = 0;
	while (line && line[i])
	{
		is_in_quote(line[i], &sq, &dq);
		if (line[i] == '$' && !(sq % 2))
		{
			j = i;
			save = dq;
			while (line[j] && line[j] != ' ' && save == dq && !(sq % 2))
			{
				is_in_quote(line[j], &sq, &dq);
				j++;
			}
			line = search_var_in_env(line, line + i, (j - i), data->env);
		}
		i++;
	}

}
