/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:08:29 by ncrivell          #+#    #+#             */
/*   Updated: 2024/11/27 12:48:14 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_trimfin(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	slen;

	slen = ft_strlen(s1);
	j = 0;
	i = slen - 1;
	while (set[j] && i > 0)
	{
		if (s1[i] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (slen - i);
}

static int	ft_trimdebut(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j] && s1[i])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static char	*ft_mallocs(int lencopy)
{
	char	*scopy;

	if (lencopy <= 0)
	{
		scopy = malloc (1);
		if (scopy == NULL)
			return (NULL);
		scopy[0] = '\0';
		return (scopy);
	}
	else
		scopy = malloc ((lencopy + 1) * sizeof(char));
	return (scopy);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		trimdebut;
	int		trimfin;
	char	*scopy;
	int		lencopy;

	if (!s1 || !set)
		return (NULL);
	trimdebut = ft_trimdebut(s1, set);
	trimfin = ft_trimfin(s1, set);
	lencopy = (ft_strlen(s1) - (trimfin + trimdebut) + 1);
	scopy = ft_mallocs(lencopy);
	if (scopy == NULL)
		return (NULL);
	i = 0;
	while (i < lencopy)
	{
		scopy[i] = s1[trimdebut + i];
		i++;
	}
	scopy[i] = '\0';
	return (scopy);
}
