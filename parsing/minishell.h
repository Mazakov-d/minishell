/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:11:26 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/23 18:12:08 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

// #define SINGLE_Q 1
// #define DOUBLE_Q 2
#define STRUCT 3
#define VOID 4

enum type
{
	TRUNC,
	REDIR_INF,
	PIPE,
	H_DOC,
	SQ,
	DQ,
	APPEND,
	DELIM,
};

typedef struct s_data
{
	struct s_data *prev;
	char **cmds;
	struct s_data *next;
	enum type type;
	int nb_cmds;

} t_data;

int calc_nb_words(char const *s, char *delim);
void init_tokenizer(t_data *token, char *line);
void alloc_check(void *to_check, t_data *token, int mode);
void free_tab_str(char **str);
int count_pipe(char *line);
int is_echo(char *str);

#endif