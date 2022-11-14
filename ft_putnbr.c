/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:31:09 by abouassi          #+#    #+#             */
/*   Updated: 2022/11/07 22:26:52 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	len_of_n(int n)
{
	int	k;

	k = 0;
	if (n < 0 || n == 0)
	{
		k++;
	}
	while (n != 0)
	{
		k++;
		n = n / 10;
	}
	return (k);
}

int	ft_putnbr(int nb)
{
	unsigned int	nn;
	int				len;

	len = len_of_n(nb);
	if (nb < 0)
	{
		ft_putchar('-');
		nn = -nb;
	}
	else
		nn = nb;
	if (nn > 9)
	{
		ft_putnbr(nn / 10);
		nn %= 10;
	}
	ft_putchar(nn + '0');
	return (len);
}
