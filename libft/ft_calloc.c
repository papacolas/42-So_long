/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:11:33 by ncrivell          #+#    #+#             */
/*   Updated: 2024/11/27 17:22:36 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*dest;
	size_t	i;
	size_t	sizetotale;

	i = 0;
	dest = NULL;
	sizetotale = nmemb * size;
	dest = malloc(sizetotale);
	if (dest == NULL)
		return (NULL);
	while (i < sizetotale)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
