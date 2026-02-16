/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:27:39 by ncrivell          #+#    #+#             */
/*   Updated: 2024/11/21 19:59:04 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	dt;
	size_t	sc;

	i = 0;
	j = 0;
	dt = ft_strlen(dest);
	sc = ft_strlen(src);
	i = dt;
	while (src[j] && i < n -1 && n > 0)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (n <= dt)
		return (sc + n);
	if (dt < n)
		return (sc + dt);
	else
		return (0);
}
