/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:25:28 by abouassi          #+#    #+#             */
/*   Updated: 2022/11/07 22:31:58 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	len_n(unsigned int n)
{
	int	k;

	k = 0;
	if (n == 0)
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

int	ft_unsign(unsigned int nn)
{
	int	len;

	len = len_n(nn);
	if (nn > 9)
	{
		ft_unsign(nn / 10);
		nn %= 10;
	}
	ft_putchar(nn + '0');
	return (len);
}
