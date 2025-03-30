/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:11:03 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/30 16:38:02 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// check si j'ai un echo dans ma string!!!1

// recuperer la fonction split_minishell apres voir split les pipe, ensuite travailler avec

// void	init

void tokenizer(t_token **token, char *line, t_env *env)
{
	int i;
	char **split;
	t_token *tmp;

	i = 0;
	*token = (t_token *)ft_calloc(1, sizeof(t_token));
	alloc_check((*token)->cmds, *token, STRUCT);
	tmp = *token;
	split = pipe_split(line, "|");
	alloc_check(split, *token, VOID);
	while (split[i])
	{
		split[i] = expand_var(split[i], env, 0, 0);
		tmp->cmds = split_minishell(split[i]);
		alloc_check(tmp->cmds, *token, VOID);
		tmp->next = (t_token *)ft_calloc(1, sizeof(t_token));
		alloc_check(tmp->cmds, tmp, STRUCT);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		i++;
	}
}

// int	main(int ac, char **av

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
// void parse_here_doc(char *line, t_data *token, int index)
// {
// 	token->type = H_DOC;
// 	token->cmds[0] = malloc(count_my_str(line, index) * sizeof(char));
// }

// void alloc_right_size(char *line)
// {
// 	if (is())
// }

// void stock_token(t_data *token, char *line, enum token)
// {
// 	// int nb_words;

// 	// nb_words = calc_nb_words(line, " ");
// 	token->cmds = malloc(nb_words * sizeof(char *));
// 	alloc_check(token->cmds, token);
// }

// void parse_redir(t_data *token, char *line)
// {
// 	int i;

// 	i = 0;
// 	if (line[1] == '<')
// 		stock_token(token, line, H_DOC);
// }
