/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:51:41 by mknsteja          #+#    #+#             */
/*   Updated: 2024/09/26 09:01:54 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pointer;
	t_list	*ahead;

	if (!lst || !*lst || !del)
		return ;
	pointer = *lst;
	ahead = pointer->next;
	while (pointer)
	{
		del(pointer->content);
		free(pointer);
		pointer = ahead;
		if (ahead != NULL)
			ahead = ahead->next;
	}
	*lst = NULL;
	return ;
}
