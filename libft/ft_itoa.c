/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:22:28 by ncrivell          #+#    #+#             */
/*   Updated: 2024/11/21 19:13:41 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_convert(long nbr, int destlen, int neg)
{
	char	*dest;
	long	tempnbr;

	if (nbr < 0)
	{
		neg = neg + 1;
		nbr = nbr * (-1);
	}
	dest = malloc ((destlen + 1 + neg) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[destlen + neg] = '\0';
	if (neg == 1)
		dest[0] = '-';
	if (nbr == 0)
		dest[0] = '0';
	while (nbr >= 1)
	{
		destlen--;
		tempnbr = nbr % 10;
		dest[destlen + neg] = tempnbr + '0';
		nbr = nbr / 10;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*dest;
	int		i;
	int		destlen;
	int		neg;

	neg = 0;
	i = 0;
	nbr = n;
	while (nbr)
	{
		nbr = nbr / 10;
		i++;
	}
	nbr = n;
	if (nbr == 0)
		destlen = 1;
	else
		destlen = i;
	dest = ft_convert(nbr, destlen, neg);
	if (dest == NULL)
		return (NULL);
	return (dest);
}
