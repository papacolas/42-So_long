/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:02:30 by ncrivell          #+#    #+#             */
/*   Updated: 2024/11/21 15:02:04 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *)big);
	while ((i < len) && (big[i] != '\0'))
	{
		j = 0;
		while ((j + i < len) && (big[i + j] == little[j]))
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
	i++;
	}
	return (NULL);
}
