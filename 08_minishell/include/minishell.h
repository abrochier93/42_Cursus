#ifndef MINISHELL_H
# define MINISHELL_H

/* INCLUDES */
# include "../src/libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/types.h>
# include <dirent.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <errno.h>

/* CONSTANTS */
# define SUCCESS 0
# define FAILURE -1
# define OPERATORS "|<>"
# define QUOTES "\"\'"
# define DELIMS "\"\' "
# define REDIRECTS "><"
# define NOT_FOUND NULL

/* SHELL ERROR MESSAGES */
# define CL_ARGUMENTS_ERR "miishell: no support for command-line arguments"
# define NO_PIPE_PROMPT "miishell: no support for pipe prompt"
# define NO_SYTX_PROMPT "miishell: no support for syntax prompt"
# define PIPE_ERR "miishell: pipe() failed"
# define FORK_ERR "miishell: fork() failed"

/* SYNTAX ERROR MESSAGES */
# define UNCLOSED_QUOTES "miishell: unclosed quotes"
# define UNEXPECTED_TOKEN "miishell: syntax error near unexpected token `"
# define SYTX_ERR_RDR "miishell: syntax error near unexpected token `newline'"

/* EXIT CMD ERROR MESSAGES */
# define EXIT_TOO_MANY_ARGS "miishell: exit: too many arguments"
# define EXIT_NON_NUMERIC_ARG "miishell: exit: numeric argument required" 

/* CD CMD ERROR MESSAGES */
# define PATH_MAX	4096
# define CD_TOO_MANY_ARGS "miishell: cd: too many arguments"
# define OLDPWD_NOT_SET "miishell: cd: OLDPWD not set"

/* STRUCT LIST */
typedef enum e_operator {
	NONE,
	RDR_OUT_REPLACE,
	RDR_OUT_APPEND,
	RDR_INPUT,
	RDR_INPUT_UNTIL,
	PIPE,
}				t_operator;

typedef struct s_statement {
	int					argc;
	char				**argv;
	t_operator			operator;
	struct s_statement	*next;
}				t_statement;

typedef struct s_vlst {
	char			*var_name;
	char			*var_value;
	bool			is_exported;
	struct s_vlst	*next;
}				t_vlst;

typedef struct s_data {
	char		**envp;
	t_vlst		*envp_lst;
	t_statement	*head;
}				t_mini;

/* INIT AND SIGNALS */
void				child_signals(int signum);
void				dismiss_signal(int signum);
void				setup_shell(char **envp, t_mini *data,
						t_statement **statement_list);

/* COMMANDS */
bool				builtin(t_statement *statement, t_mini *data);
void				cmd_binaries(t_statement *statement, t_mini *data);
int					cmd_echo(t_statement *statement, bool has_n);
int					cmd_pwd(void);
int					cmd_cd(char *path, t_mini *data);
int					cmd_env(t_mini *data);
int					cmd_export(t_statement *statement, t_mini *data);
void				cmd_exit(t_statement *s, t_mini *data);
void				call_cmd_exit(t_statement *statement, t_mini *data);
int					unset_var(char *var_name, t_vlst **head);
int					cmd_unset(t_statement *s, t_vlst **head);

/* COMMANDS UTILS*/
int					cd_too_many_args(void);
void				cmd_not_found(char *cmd_name);
bool				is_absolute_path(t_statement *statement);
bool				is_valid_id(char *str);
bool				streq(char *str1, char *str2);
void				free_matrix(char **matrix);
char				*join_free(char *s1, char *s2);
bool				is_spaces(char c);
bool				is_onstr(const char *str, int ch);
int					unclosed_quotes(char *str);
bool				invalid_syntax(char *input);
bool				invalid_syntax2(char *input);
bool				invalid_syntax_on_operator(char *input);
bool				valid_input(char *input, t_mini *data);
bool				is_all_digits_or_signals(char *str);
void				destroy(t_mini *data);
void				config_signals(void);
void				exec_cmd(t_statement *current_node, t_mini *data);
void				exec_type(t_statement *statement_list, t_mini *data);
void				exec_executables(t_statement *node, t_mini *data);
void				exec_pipe(t_statement *node, t_mini *data);
void				exec_redirects(t_statement *node, t_mini *data);

/* LINKED LIST*/
t_statement			*p_new_node(int argc);
size_t				p_lstsize(t_statement *head);
void				p_lstclear(t_statement **head);
t_vlst				*v_new_node(char *var_name, char *var_value,
						bool is_exported);
void				v_lstadd_back(t_vlst **head, t_vlst *new);
t_vlst				*v_lstlast(t_vlst *node);
size_t				v_lstsize_exported(t_vlst **head);
void				v_lstclear(t_vlst **head);
bool				get_exported_state(char *var_name, t_vlst **head);
char				**get_envp_arr(t_vlst **envp_lst);
char				*get_fromvlst(char *var_name, t_vlst **head);
char				*get_varvalue_fromvlst(char *var_name, t_mini *data);
char				**split_envp(char *env);
int					save_user_vars(char *statement, t_vlst **head,
						bool to_export);
t_vlst				*init_envp_lst(char **envp);
size_t				get_nr_statements(char *input);
char				*remove_quotes(char	*parsed);

/* FORMATER UTILS*/
size_t				exit_status_size(void);
size_t				format_size(char *input, size_t *i, t_mini *data);
int					formated_size(char *input, t_mini *data);
bool				single_dollar(char *input_at_i);
void				init_vars(size_t *i, size_t *size, bool *in_quotes, bool *in_dquotes);
char				*formater(char *input, t_mini *data);

/* PARSER UTILS*/
t_operator			get_operator(char *operator);
size_t				get_argc(char **parsed);
size_t				get_token_len(char *input_at_i);
size_t				get_nr_statements(char *input);
t_statement			*parser(char *input);
void				print_operator(t_operator operator);
void				error(t_mini *data, char *error_msg, int exit_status);

#endif