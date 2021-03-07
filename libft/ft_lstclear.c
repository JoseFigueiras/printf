#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;
	t_list	*current;

	if (!lst || !*lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		prev = current;
		current = current->next;
		del(prev->content);
		free((void *)prev);
	}
	*lst = NULL;
}
