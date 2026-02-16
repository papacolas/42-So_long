/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:20:30 by ncrivell          #+#    #+#             */
/*   Updated: 2024/11/23 20:03:35 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_countdel(char const *s, char c)
{
	int	i;
	int	del;

	del = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			del++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (del);
}

static char	*ft_strsplt(char const *s, int debut, int lenstr)
{
	char	*dest;
	int		i;

	dest = malloc ((lenstr + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < (lenstr))
	{
		dest[i] = s[debut + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	ft_freedest(char **dest)
{
	int	ifree;

	ifree = 0;
	while (dest[ifree])
	{
		free(dest[ifree]);
		ifree++;
	}
	free(dest);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**dest;
	int		k;
	int		debut;

	k = 0;
	i = 0;
	dest = malloc ((ft_countdel(s, c) + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			debut = i;
			while (s[i] != c && s[i])
				i++;
			dest[k++] = ft_strsplt(s, debut, i - debut);
			if (!dest[k - 1])
				return (ft_freedest(dest), NULL);
		}
	}
	return (dest[k] = (NULL), dest);
}
