/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paramptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imamasol <imamasol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:07:04 by imamasol          #+#    #+#             */
/*   Updated: 2025/07/07 10:11:13 by imamasol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_paramptr(void *ptr, int *len)
{
	char			*str;
	unsigned long	addr;

	addr = (unsigned long)ptr;
	str = ft_hexconvert(addr, 0);
	if (addr == 0)
	{
		ft_putstr_fd("0x0", 1);
		free(str);
		(*len) += 3;
	}
	else if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		(*len) += 6;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(str, 1);
		(*len) += ft_strlen(str) + 2;
		free(str);
	}
	return (2);
}
