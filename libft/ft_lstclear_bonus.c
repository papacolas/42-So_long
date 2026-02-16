/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:23:54 by ncrivell          #+#    #+#             */
/*   Updated: 2024/11/21 15:02:33 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tempnode;

	if (*lst != NULL && del != NULL)
	{
		while ((*lst))
		{
			tempnode = (*lst)->next;
			del((*lst)->content);
			free (*lst);
			*lst = tempnode;
		}
		*lst = NULL;
	}
}
