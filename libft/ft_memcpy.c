/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:56:47 by ncrivell          #+#    #+#             */
/*   Updated: 2024/11/21 15:00:09 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dt;
	unsigned char	*sc;

	if (dest == NULL && src == NULL)
		return (NULL);
	sc = (unsigned char *)src;
	dt = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		dt[i] = sc[i];
		i++;
	}	
	return (dest);
}
