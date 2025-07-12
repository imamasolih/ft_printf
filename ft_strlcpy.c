/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imamasol <imamasol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:59:13 by imamasol          #+#    #+#             */
/*   Updated: 2025/07/12 12:59:57 by imamasol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;

	n = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (n < (size - 1) && src[n])
	{
		dst[n] = src[n];
		n++;
	}
	dst[n] = 0;
	return (ft_strlen(src));
}
