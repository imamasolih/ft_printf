/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paramptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imamasol <imamasol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:07:04 by imamasol          #+#    #+#             */
/*   Updated: 2025/07/07 12:54:41 by imamasol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_paramptr(void *ptr, int *len)
{
	unsigned long	addr;
	char			*str;

	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		(*len) += 5;
		return (2);
	}
	addr = (unsigned long)ptr;
	str = ft_hexconvert(addr, 0);
	if (str == NULL)
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
