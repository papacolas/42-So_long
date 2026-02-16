/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:40:17 by ncrivell          #+#    #+#             */
/*   Updated: 2024/11/23 20:19:13 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*n_node;

	n_node = malloc (sizeof(t_list));
	if (n_node == NULL)
		return (NULL);
	n_node->content = content;
	n_node->next = NULL;
	return (n_node);
}
