/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imamasol <imamasol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:10:12 by imamasol          #+#    #+#             */
/*   Updated: 2025/07/07 11:16:42 by imamasol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nmcount(int num)
{
	int		i;
	int		tens;

	i = 1;
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	tens = 1;
	while ((num / tens) >= 10)
	{
		tens *= 10;
		i++;
	}
	return (i);
}
static char	*ft_edge(void)
{
	char	*result;

	result = (char *)malloc(12);
	if (!result)
		return (NULL);
	ft_strlcpy(result, "-2147483648", 12);
	return (result);
}
static int	ft_checkneg(int *num)
{
	int	ind;

	ind = 0;
	if (*num < 0)
	{
		*num *= -1;
		ind = 1;
	}
	return (ind);
}

char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*asnum;

	if (n == -2147483648)
		return (ft_edge());
	len = ft_nmcount(n);
	asnum = (char *)malloc(len + 1);
	if (!asnum)
		return (NULL);
	asnum[len] = '\0';
	neg = ft_checkneg(&n);
	while (len-- > 0)
	{
		if (len == 0 && neg)
		{
			asnum[0] = '-';
			break ;
		}
		asnum[len] = (n % 10) + '0';
		n /= 10;
	}
	return (asnum);
}
