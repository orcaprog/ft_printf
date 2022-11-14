/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:14:27 by abouassi          #+#    #+#             */
/*   Updated: 2022/11/08 10:24:57 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	llen(unsigned int ptr)
{
	int	k;

	k = 0;
	if (ptr == 0)
	{
		k++;
	}
	while (ptr > 0)
	{
		ptr = ptr / 16;
		k++;
	}
	return (k);
}

int	ft_hexa(unsigned int ptr, int c)
{
	int				len;
	unsigned int	rmnd;

	len = llen(ptr);
	if (ptr >= 16)
	{
		ft_hexa((ptr / 16), c);
	}
	rmnd = ptr % 16;
	if (rmnd >= 0 && rmnd <= 9)
	{
		ft_putchar(rmnd + 48);
	}
	else
		ft_putchar(rmnd + c);
	return (len);
}
