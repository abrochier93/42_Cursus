#include "../../include/minishell.h"

extern long long	g_exit_status;

size_t	format_exit_status(char *formated_input_at_i, size_t *i)
{
	char	*exit_status;
	size_t	j;

	*i += 2;
	exit_status = ft_itoa(g_exit_status);
	j = 0;
	while (exit_status[j])
	{
		formated_input_at_i[j] = exit_status[j];
		j += 1;
	}
	free(exit_status);
	return (j);
}

size_t	format_variable(char *formated_input_at_i, char *input,
	size_t *i, t_mini *data)
{
	char	*var_value;
	size_t	size;
	size_t	j;
	size_t	k;

	size = 0;
	j = 0;
	k = 0;
	*i += 1;
	if (!input[*i] || input[*i] == ' ' || input[*i] == '\"')
	{
		formated_input_at_i[0] = '$';
		return (1);
	}
	while (input[*i + size] && input[*i + size] != ' '
		&& input[*i + size] != '\"' && !is_onstr(QUOTES, input[*i + size])
		&& input[*i + size] != '$')
		size += 1;
	var_value = get_varvalue_fromvlst(ft_substr(input, *i, size), data);
	*i += size;
	if (!var_value)
		return (0);
	while (var_value[k])
		formated_input_at_i[j++] = var_value[k++];
	return (j);
}

char	*formater(char *input, t_mini *data)
{
	size_t	i;
	size_t	j;
	bool	in_quotes;
	bool	in_dquotes;
	char	*formated_input;

	init_vars(&i, &j, &in_quotes, &in_dquotes);
	formated_input = malloc((formated_size(input, data) + 1) * sizeof(char));
	while (input[i])
	{
		if (input[i] == '\"' && !in_quotes)
			in_dquotes = !in_dquotes;
		if (input[i] == '\'' && !in_dquotes)
			in_quotes = !in_quotes;
		if (input[i] == '$' && input[i + 1] == '?' && !in_quotes)
			j += format_exit_status(&(formated_input[j]), &i);
		else if (input[i] && input[i] == '$' && !in_quotes)
			j += format_variable(&(formated_input[j]), input, &i, data);
		else
			formated_input[j++] = input[i++];
	}
	formated_input[j] = '\0';
	free(input);
	return (formated_input);
}
