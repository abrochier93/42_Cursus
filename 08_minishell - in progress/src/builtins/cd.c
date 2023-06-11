#include "../../include/minishell.h"


void	update_pwd(char **env)
{
	char	*new_path;
	char	*read_cwd;
	int		i;
	int		j;

	new_path = NULL;
	read_cwd = getcwd(NULL, 0);
	if (read_cwd == NULL)
		return ;
	i = ft_check_env(env, "PWD");
	if (i >= 0)
	{
		j = -1;
		free(env[i]);
		new_path = ft_strjoin("PWD=", getcwd(new_path, \
		ft_strlen(read_cwd) + 1));
		env[i] = malloc(sizeof(char) * (ft_strlen(new_path) + 1));
		while (new_path[++j] != '\0')
			env[i][j] = new_path[j];
		env[i][j] = '\0';
	}
	free(read_cwd);
	free(new_path);
}

void	update_oldpwd(char **env)
{
	char	*new_path;
	char	*read_cwd;
	int		i;
	int		j;

	new_path = NULL;
	read_cwd = getcwd(NULL, 0);
	if (read_cwd == NULL)
		return ;
	i = ft_check_env(env, "OLDPWD");
	if (i >= 0)
	{
		j = -1;
		free(env[i]);
		new_path = ft_strjoin("OLDPWD=", getcwd(new_path, \
		ft_strlen(read_cwd) + 1));
		env[i] = malloc(sizeof(char) * (ft_strlen(new_path) + 1));
		while (new_path[++j] != '\0')
			env[i][j] = new_path[j];
		env[i][j] = '\0';
	}
	free(read_cwd);
	free(new_path);
}

char	*ft_format_path(char *path)
{
	char *temp;
	int i;

	temp = path;
	if (path == NULL || ft_strncmp(path, "~", 2) == 0)
	{
		temp = ft_strjoin(getenv("HOME"), "/");
		return (temp);
	}
	if (ft_strncmp(path, "..", 3) == 0)
	{
		i = 0;
		while (path[i])
			i++;
		temp = ft_calloc(sizeof(char), i);
		while (path[i] != '/')
			path[i] = '\0';
	}
	return (path);
}

char	*get_oldpwd(char **env)
{
	char	*oldpwd;
	int		i;

	oldpwd = NULL;
	i = ft_check_env(env, "OLDPWD");
	if (i >= 0)
	{
		oldpwd = malloc(sizeof(char) * (ft_strlen(env[i]) + 1));
		oldpwd = ft_strdup(env[i]);
	}
	return (oldpwd);
}

void	reset_old_pwd(char *old_pwd, char **env)
{
	int i;
	int j;

	j = -1;
	i = ft_check_env(env, "OLDPWD");
	if (i >= 0)
	{
		free(env[i]);
		env[i] = malloc(sizeof(char) * (ft_strlen(old_pwd) + 1));
		while (old_pwd[++j] != '\0')
			env[i][j] = old_pwd[j];
		env[i][j] = '\0';
	}
}

int	ft_cd(t_prompt *s_prompt, t_mini *data)
{
	char *path;
	char *error;
	char *old_pwd;

	error = ft_strjoin("miishell ~ cd : ", path);
	old_pwd = get_oldpwd(data->env_cpy);
	path = s_prompt->arg;
	if (ft_strncmp(s_prompt->cmd, "cd", 3) == 0)
	{
		update_oldpwd(data->env_cpy);
		if (chdir(path) != 0)
		{
			reset_old_pwd(old_pwd, data->env_cpy);
			perror(error);
			return (0);
		}
		path = ft_format_path(path);
		chdir(path);
		update_pwd(data->env_cpy);
		return (0);
	}
	return (1);
}