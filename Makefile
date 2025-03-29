NAME= minishell
CC=cc
FLAGS= -Wall -Wextra -Werror
LIBS = -lreadline
OBJDIR = .obj
SRCS=main.c  parsing/*.c builtins/*.c
HEADERS= includes/builtin.h includes/env.h includes/minishell.h
OBJS=$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
all: $(NAME)
$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)
$(OBJDIR)/%.o: %.c $(HEADERS)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(OPTS) -c $< -o $@
clean:
	rm -rf $(OBJDIR)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re