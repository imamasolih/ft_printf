/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paramhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imamasol <imamasol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:06:58 by imamasol          #+#    #+#             */
/*   Updated: 2025/07/07 10:40:37 by imamasol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_paramhex(unsigned long addr, int flag, int *len)
{
	char *str;

	str = ft_hexconvert(addr, flag);

	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		len += 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		len += ft_strlen(str);
		free(str);
	}
	return (2);
}
