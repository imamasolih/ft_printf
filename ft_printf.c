/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imamasol <imamasol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:08:08 by imamasol          #+#    #+#             */
/*   Updated: 2025/07/12 13:06:39 by imamasol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_handler(const char *src, va_list arg, int *len)
{
	char	param;

	param = src[1];
	if (param == 'c')
		return (ft_paramchar(va_arg(arg, int), len));
	if (param == 's')
		return (ft_paramstr(va_arg(arg, char *), len));
	if (param == 'p')
		return (ft_paramptr(va_arg(arg, void *), len));
	if (param == 'd' || param == 'i')
		return (ft_paramint(va_arg(arg, int), len));
	if (param == 'u')
		return (ft_paramunt(va_arg(arg, unsigned int), len));
	if (param == 'x' || param == 'X')
		return (ft_paramhex((unsigned long)va_arg(arg, unsigned int),
				(param == 'X'), len));
	if (param == '%')
		return (ft_paramper(len));
	else
	{
		(*len) += 2;
		write(1, src, 1);
		write(1, &param, 1);
		return (2);
	}
}

int	ft_printf(const char *ftext, ...)
{
	int		i;
	int		len;
	va_list	argc;

	i = 0;
	len = 0;
	va_start(argc, ftext);
	while (ftext[i])
	{
		if (ftext[i] == '%' && ftext[i + 1])
			i += format_handler(&ftext[i], argc, &len);
		else
			len += write(1, &ftext[i++], 1);
	}
	va_end(argc);
	return (len);
}
