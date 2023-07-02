#include "../../include/minishell.h"

void	v_lstclear(t_vlst **head)
{
	t_vlst	*temp;
	t_vlst	*next_node;

	if (!head)
		return ;
	temp = *head;
	while (temp != NULL)
	{
		next_node = temp->next;
		free(temp->var_name);
		free(temp->var_value);
		free(temp);
		temp = next_node;
	}
	*head = NULL;
}

void	destroy(t_mini *data)
{
	rl_clear_history();
	if (data->envp_lst)
		v_lstclear(&data->envp_lst);
	if (data->head)
		p_lstclear(&data->head);
}
