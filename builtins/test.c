#include "builtin.h"

// int main(int ac, char **av, char **env)
// {
// 	t_env *ev;
// 	char	*str;	

// 	str = ft_strdup("PATHE=a");
// 	ev = env_to_struct(env);
// 	// while (ev->next)
// 	// {
// 	// 	printf("%s\n", ev->line);
// 	// 	ev = ev->next;
// 	// }
// 	// while (ev->prev)
// 	// 	ev = ev->prev;
// 	ft_export(ev, str);
// 	ft_env(ev);
// 	printf("\n\n\n");
// 	ft_unset(ev, str);
// 	ft_env(ev);
// 	free_new_env(ev);
// }