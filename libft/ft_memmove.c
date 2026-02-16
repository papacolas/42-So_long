/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:09:16 by ncrivell          #+#    #+#             */
/*   Updated: 2024/11/21 17:12:58 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t						i;
	unsigned char				*dt;
	const unsigned char			*sc;

	dt = (unsigned char *)dest;
	sc = (const unsigned char *)src;
	i = -1;
	if (dt == sc)
		return (dest);
	if (dt < sc)
	{
		while (++i < n)
			dt[i] = sc[i];
	}
	else
	{
		while (n--)
			dt[n] = sc[n];
	}
	return (dest);
}
