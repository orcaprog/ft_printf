/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:12:08 by abouassi          #+#    #+#             */
/*   Updated: 2022/11/08 09:57:51 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	l_en(unsigned long ptr)
{
	int	k;

	k = 0;
	if (ptr == 0)
	{
		k++;
	}
	while (ptr != 0)
	{
		ptr = ptr / 16;
		k++;
	}
	return (k);
}

static int	ptrhx(unsigned long ptr)
{
	int	len;
	int	rmnd;

	len = 0;
	len = l_en(ptr);
	if (ptr >= 16)
	{
		ptrhx(ptr / 16);
	}
	rmnd = ptr % 16;
	if (rmnd >= 0 && rmnd <= 9)
	{
		ft_putchar(rmnd + 48);
	}
	else
		ft_putchar(rmnd + 87);
	return (len);
}

int	ft_ptrhex(unsigned long ptr)
{
	int	len;

	len = 0;
	len = ft_putstr("0x");
	len += ptrhx(ptr);
	return (len);
}
