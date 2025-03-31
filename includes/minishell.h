/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:11:26 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/31 14:00:05 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "builtin.h"
# include "env.h"
# include "utils.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

/*
** Macros for token types
*/
# define STRUCT 3
# define VOID 4

/*
** Enum for token types
*/
enum e_type
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

/*
** Token structure for command parsing
*/
typedef struct s_token
{
	char			**cmds;
	enum e_type		type;
	int				nb_cmds;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

/*
** Data structure for command processing
*/
typedef struct s_data
{
	char		**cmds;
	t_token		*first;
	enum e_type	type;
	int			nb_cmds;
	t_env		*env;
	int			status;
}	t_data;

/*
** Global structure for shell state
*/
typedef struct s_all
{
	t_token	*token;
	t_env	*env;
	int		status;
}	t_all;

/*
** Parsing utility functions
*/
int		calc_nb_words(char const *s, char *delim);
void	alloc_check(void *to_check, t_token *token, int mode);
void	free_tab_str(char **str);
int		count_pipe(char *line);
int		is_echo(char *str);
void	is_in_sq(char c, int *sq);
int		pos_in_str(char *str, char c);
void	*ft_calloc(size_t nmemb, size_t size);

/*
** String splitting and tokenization
*/
char	**pipe_split(char const *s, char *delim);
char	**split_minishell(char *str);
void	tokenizer(t_token **token, char *line, t_env *env);
int		word_len(char *str);
char	*str_dup_minishell(char *s, int *i, int k, int j);

/*
** Variable expansion
*/
char	*expand_var(char *line, t_env *env, int i, int j);

/*
** Input verification
*/
int		is_closed(char *line);

/*
** Debug functions
*/
void	disp_tab_str(char **str);
void	disp_data(t_token *token);

#endif