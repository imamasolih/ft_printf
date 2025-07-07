/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imamasol <imamasol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:10:12 by imamasol          #+#    #+#             */
/*   Updated: 2025/07/07 11:19:35 by imamasol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nmcount(unsigned int num)
{
	int		i;
	int		tens;

	i = 1;
	tens = 1;
	while ((num / tens) >= 10)
	{
		tens *= 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*asnum;

	len = ft_nmcount(n);
	asnum = (char *)malloc(len + 1);
	if (!asnum)
		return (NULL);
	asnum[len] = '\0';
	while (len-- > 0)
	{
		asnum[len] = (n % 10) + '0';
		n /= 10;
	}
	return (asnum);
}
