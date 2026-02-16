/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:00:15 by ncrivell          #+#    #+#             */
/*   Updated: 2024/11/21 17:51:17 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_lencopy(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc ((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_startcopy(char const *s, unsigned int start)
{
	char	*dest;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	dest = malloc (((slen - start) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < slen - start)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	if (start >= slen || !s)
	{
		dest = malloc (sizeof(char));
		if (dest == NULL)
			return (NULL);
		dest[i] = '\0';
	}
	else
	{
		if (len < (slen - start))
			dest = ft_lencopy(s, start, len);
		else
			dest = ft_startcopy(s, start);
	}
	if (dest == NULL)
		return (NULL);
	else
		return (dest);
}
