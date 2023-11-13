/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:02:06 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/11/13 15:46:01 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	f(char *str, int fd)
{
	int	a;

	ft_putstr_fd(str, fd);
	a = ft_strlen(str);
	free(str);
	return (a);
}

int	nf(char *str, int fd)
{
	int	a;

	if (!str)
		return (write(fd, "(null)", 6));
	ft_putstr_fd(str, fd);
	a = ft_strlen(str);
	return (a);
}

int	ft_isparam(char c, va_list arg, int fd)
{
	if (c == 's')
		return (nf(va_arg(arg, char *), fd));
	else if (c == 'i' || c == 'd')
		return (f(ft_itoa(va_arg(arg, int)), fd));
	else if (c == '%')
		return (write(fd, "%", 1));
	else if (c == 'c')
	{
		ft_putchar_fd(va_arg(arg, int), fd);
		return (1);
	}
	else if (c == 'x')
		return (f(ft_itoa_base(va_arg(arg, unsigned int), HEX), fd));
	else if (c == 'X')
		return (f(ft_itoa_base(va_arg(arg, unsigned int), HEX_C), fd));
	else if (c == 'u')
		return (f(ft_itoa_base(va_arg(arg, unsigned int), DEC), fd));
	else if (c == 'p')
	{
		ft_putstr_fd("0x", fd);
		return (f(ft_itoa_base(va_arg(arg, unsigned long long int),
					HEX), fd) + 2);
	}
	else
		return (0);
}

int	ft_fprintf(int fd, const char *strparam, ...)
{
	va_list	args;
	int		i;
	int		ct;

	ct = 0;
	i = 0;
	va_start(args, strparam);
	while (strparam[i])
	{
		if (strparam[i] == '%')
		{
			ct += ft_isparam(strparam[i + 1], args, fd);
			i += 2;
		}
		if (strparam[i] && strparam[i] != '%')
		{
			ft_putchar_fd(strparam[i++], fd);
			ct++;
		}
	}
	va_end(args);
	return (ct);
}

int	ft_printf(const char *strparam, ...)
{
	va_list	args;
	int		i;
	int		ct;

	ct = 0;
	i = 0;
	va_start(args, strparam);
	while (strparam[i])
	{
		if (strparam[i] == '%')
		{
			ct += ft_isparam(strparam[i + 1], args, 1);
			i += 2;
		}
		if (strparam[i] && strparam[i] != '%')
		{
			ft_putchar_fd(strparam[i++], 1);
			ct++;
		}
	}
	va_end(args);
	return (ct);
}
