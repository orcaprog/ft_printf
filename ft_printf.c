/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:18:12 by abouassi          #+#    #+#             */
/*   Updated: 2022/11/08 10:56:08 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	aravalu(char format, va_list va)
{
	int	x;

	x = 0;
	if (format == 'c')
		x += ft_putchar(va_arg(va, int));
	else if (format == '%')
		x += ft_putchar('%');
	else if (format == 'u')
		x += ft_unsign(va_arg(va, unsigned int));
	else if (format == 's')
		x += ft_putstr(va_arg(va, char *));
	else if (format == 'd' || format == 'i')
		x += ft_putnbr(va_arg(va, int));
	else if (format == 'x')
		x += ft_hexa(va_arg(va, unsigned int), 87);
	else if (format == 'X')
		x += ft_hexa(va_arg(va, unsigned int), 55);
	else if (format == 'p')
		x += ft_ptrhex(va_arg(va, unsigned long));
	else
		x += ft_putchar(format);
	return (x);
}

int	ft_printf(const char *format, ...)
{
	va_list	va;
	int		i;
	int		len;

	va_start(va, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (len);
		if (format[i] == '%')
		{
			len += aravalu(format[i + 1], va);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(va);
	return (len);
}
