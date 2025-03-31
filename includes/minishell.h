/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:11:26 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/31 13:12:54 by dorianmazar      ###   ########.fr       */
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

// #define SINGLE_Q 1
// #define DOUBLE_Q 2
# define STRUCT 3
# define VOID 4

enum	e_type
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

typedef struct s_token
{
	char			**cmds;
	enum e_type		type;
	int				nb_cmds;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_data
{
	char		**cmds;
	t_token		*first;
	enum e_type	type;
	int			nb_cmds;
	t_env		*env;
	int			status;
}	t_data;

typedef struct s_all
{
	t_token	*token;
	t_env	*env;
	int		status;
}	t_all;

// void 	init_tokenizer(t_data *token, char *line);
int		calc_nb_words(char const *s, char *delim);
void	alloc_check(void *to_check, t_token *token, int mode);
void	free_tab_str(char **str);
int		count_pipe(char *line);
int		is_echo(char *str);
void	is_in_quote(char c, int *sq, int *dq);
char	**pipe_split(char const *s, char *delim);
int		pos_in_str(char *str, char c);
void	is_in_sq(char c, int *sq);
char	**pipe_split(char const *s, char *delim);
void	*ft_calloc(size_t nmemb, size_t size);
char	**split_minishell(char *str);
void	tokenizer(t_token **token, char *line, t_env *env);
char	*expand_var(char *line, t_env *env, int i, int j);
// void free_data(t_data **token);

#endif
