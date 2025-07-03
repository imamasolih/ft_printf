
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *src, ...)
{
	int				i;
	int				len;
	char			*str;
	va_list			argc;
	unsigned long	addr;

	va_start(argc, src);
	i = 0;
	len = 0;
	while (src[i])
	{
		if (src[i] == '%' && src[i + 1])
		{
			if (src[i + 1] == 's')
			{
				str = va_arg(argc, char *);
				if (str == NULL)
					str = "(null)";
				ft_putstr_fd(str, 1);
				len += ft_strlen(str);
				i += 2;
				continue ;
			}
			else if (src[i + 1] == 'c')
			{
				ft_putchar_fd(va_arg(argc, int), 1);
				len++;
				i += 2;
				continue ;
			}
			else if (src[i + 1] == 'd' || src[i + 1] == 'i')
			{
				str = ft_itoa(va_arg(argc, int));
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
				i += 2;
				continue ;
			}
			else if (src[i + 1] == 'u')
			{
				str = ft_utoa(va_arg(argc, unsigned int));
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
				i += 2;
				continue ;
			}
			else if (src[i + 1] == 'p')
			{
				addr = (unsigned long)va_arg(argc, void *);
				str = ft_hexconvert(addr, 0);
				if (addr == 0)
				{
					ft_putstr_fd("0x0", 1);
					free(str);
					len += 3;
				}
				else if (str == NULL)
				{
					ft_putstr_fd("(null)", 1);
					len += 6;
				}
				else
				{
					ft_putstr_fd("0x", 1);
					ft_putstr_fd(str, 1);
					len += ft_strlen(str) + 2;
					free(str);
				}
				i += 2;
				continue ;
			}
			else if (src[i + 1] == 'x' || src[i + 1] == 'X')
			{
				addr = (unsigned long)va_arg(argc, unsigned int);
				if (src[i + 1] == 'x')
					str = ft_hexconvert(addr, 0);
				else
					str = ft_hexconvert(addr, 1);
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
				i += 2;
				continue ;
			}
			else if (src[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
				len++;
				i += 2;
				continue ;
			}
			else
			{
				write(1, &src[i], 1);
				len++;
				i++;
				continue ;
			}
		}
		else
		{
			write(1, &src[i], 1);
			len++;
			i++;
		}
	}
	va_end(argc);
	return (len);
}

/* int	main(void)
{
	int i = 50;

	ft_printf("Hello %s, value: %d, hex: %x, ptr: %p, percent: %% and final\n",
		"world", 42, 48879, &i);
	printf("Hello %s, value: %d, hex: %x, ptr: %p, percent: %%\n", "world", 42,
		48879, &i);

	return (0);
} */