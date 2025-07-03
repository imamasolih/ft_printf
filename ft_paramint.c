/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paramint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imamasol <imamasol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:52:18 by imamasol          #+#    #+#             */
/*   Updated: 2025/07/03 18:07:23 by imamasol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_paramint(int num, int *len)
{
	char *str;

	str = ft_itoa(num);
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
