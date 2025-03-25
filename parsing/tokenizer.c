/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:11:03 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/25 17:29:33 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check si j'ai un echo dans ma string!!!1

// recuperer la fonction split_minishell apres voir split les pipe, ensuite travailler avec

void	init

void tokenizer(t_data **token, char *line)
{
	int i;
	int j;
	char **split;
	t_data	*tmp;

	i = 0;
	tmp
	token = (t_data *)malloc((count_pipe(line) + 1) * sizeof(t_data));
	alloc_check(token->cmds, token, STRUCT);
	tmp = *token;
	split = ft_split(line, "|");
	alloc_check(split, token, VOID);
	while (split[i])
	{
		if (!is_echo(split[i]))
		{
			tmp->cmds = split_minishell(split[i]);
			allo_check(token->cmds, token, VOID);
			handle_token(token);
			tmp = tmp->next;
		}
		i++;
	}
}

// void	handle_token(t_data *token)
// {
// 	int		i;
// 	t_data	*tmp;

// 	i = 0;
// 	tmp = token;
// 	while ()
// }
// while (line && line[i] && line[i] == ' ')
// 	i++;
// {
// 	if (line[i + 1] == '<')
// 		parse_here_doc(token, line, i + 1);
// 	else
// 		parse_infile(token, line, i);
// }
// else if (line[i] == '>')
// {
// 	if (line[i + 1] == '>')
// 		parse_outfile(token, line, i, APPEND);
// 	else
// 		parse_outfile(token, line, i, TRUNC);
// }
// else
// 	parse_command(token, line, i);
// set_tokenizer(token, line)
// }
void parse_here_doc(char *line, t_data *token, int index)
{
	token->type = H_DOC;
	token->cmds[0] = malloc(count_my_str(line, index) * sizeof(char));
}
void alloc_right_size(char *line)
{
	if (is())
}

// void stock_token(t_data *token, char *line, enum token)
// {
// 	// int nb_words;

// 	// nb_words = calc_nb_words(line, " ");
// 	token->cmds = malloc(nb_words * sizeof(char *));
// 	alloc_check(token->cmds, token);
// }

void parse_redir(t_data *token, char *line)
{
	int i;

	i = 0;
	if (line[1] == '<')
		stock_token(token, line, H_DOC);
}
