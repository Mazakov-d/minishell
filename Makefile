NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBS = -lreadline

# Directories
OBJDIR = .obj
PARSEDIR = parsing
BUILTINSDIR = builtins
UTILSDIR = utils_str

# Source files - explicit listing instead of wildcards
SRCS = main.c \
	$(PARSEDIR)/expand.c \
	$(PARSEDIR)/expand_line.c \
	$(PARSEDIR)/expand_null.c \
	$(PARSEDIR)/ft_calloc.c \
	$(PARSEDIR)/ft_split.c \
	$(PARSEDIR)/parse_utils.c \
	$(PARSEDIR)/parsing.c \
	$(PARSEDIR)/tokenizer.c \
	$(BUILTINSDIR)/env_functions.c \
	$(BUILTINSDIR)/env_parsing.c \
	$(BUILTINSDIR)/ft_cd.c \
	$(BUILTINSDIR)/ft_echo.c \
	$(BUILTINSDIR)/ft_env.c \
	$(BUILTINSDIR)/ft_exit.c \
	$(BUILTINSDIR)/ft_export.c \
	$(BUILTINSDIR)/ft_pwd.c \
	$(BUILTINSDIR)/ft_unset.c \
	$(UTILSDIR)/ft_char.c \
	$(UTILSDIR)/ft_strcpy.c

# Headers
HEADERS = includes/builtin.h includes/env.h includes/minishell.h includes/utils.h

# Objects
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJDIR)/%.o: %.c $(HEADERS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re