/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imamasol <imamasol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:08:56 by imamasol          #+#    #+#             */
/*   Updated: 2025/07/12 12:58:22 by imamasol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_itoa(int n);
int		ft_paramper(int *len);
size_t	ft_strlen(const char *c);
char	*ft_utoa(unsigned int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_paramchar(int c, int *len);
int		ft_paramstr(char *s, int *len);
int		ft_paramint(int num, int *len);
int		ft_paramptr(void *ptr, int *len);
int		ft_printf(const char *ftext, ...);
int		ft_paramunt(unsigned int num, int *len);
char	*ft_hexconvert(unsigned long n, int letter);
int		ft_paramhex(unsigned long addr, int flag, int *len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif