/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paramunt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imamasol <imamasol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:07:08 by imamasol          #+#    #+#             */
/*   Updated: 2025/07/03 18:14:55 by imamasol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_paramunt(unsigned int num, int *len)
{
	char	*str;

	str = ft_utoa(num);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		(*len) += 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		(*len) += ft_strlen(str);
		free(str);
	}
	return (2);
}
