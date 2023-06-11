#ifndef MINISHELL_H
# define MINISHELL_H

# include "../src/libft/libft.h"
# include "readline/history.h"
# include "readline/readline.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct s_global
{
	int	pid1;
	int	sig_int;
	
}			t_global;

typedef struct s_mini
{
	char	**env_cpy;
	char	*pwd;
}			t_mini;

typedef struct s_prompt
{
	char	*cmd;
	char	*flags;
	char	*arg;
}			t_prompt;

// libft functions
void		ft_putstr_fd(char *s, int fd);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);

// fonctions qui init qqch
void    ft_struct_init(char **envp, t_mini *shell);

// UTILS
void		parse(char *prompt);

// MAIN
int	minishell(t_mini *shell);

//BUILTINS
int	ft_cd(t_prompt *s_prompt, t_mini *data);
int	ft_echo(t_prompt *s_prompt);
int	ft_env(t_prompt *s_prompt, t_mini *data);

//BUILTINS UTILS
void	ft_print_env(char **env);
int		ft_check_env(char **env, char *var);

#endif