/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexconvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imamasol <imamasol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:42:23 by imamasol          #+#    #+#             */
/*   Updated: 2025/07/07 10:10:21 by imamasol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_divhex(int i, char *src, unsigned long num, int let_case)
{
	while (i >= 0)
	{
		if ((num % 16) < 10)
			src[i--] = (num % 16) + '0';
		else
		{
			if (let_case == 0)
				src[i--] = (num % 16) + 87;
			else
				src[i--] = (num % 16) + 55;
		}
		num /= 16;
	}
	return (src);
}

char	*ft_hexconvert(unsigned long n, int letter)
{
	int				i;
	char			*ret;
	unsigned long	temp;

	i = 1;
	temp = n;
	while ((temp / 16) > 0)
	{
		temp /= 16;
		i++;
	}
	ret = (char *)malloc(i + 1);
	if (!ret)
		return (NULL);
	ret[i--] = '\0';
	ft_divhex(i, ret, n, letter);
	return (ret);
}
