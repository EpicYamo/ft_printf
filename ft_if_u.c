/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:54:10 by aaycan            #+#    #+#             */
/*   Updated: 2024/12/06 01:21:56 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(unsigned int n, t_returnval *returnval);

void	ft_if_u(unsigned int n, t_returnval *returnval)
{
	ft_putnbr(n, returnval);
	if (n == 0)
		returnval->j += 1;
	while (n > 0)
	{
		returnval->j += 1;
		n = n / 10;
	}
}

static void	ft_putnbr(unsigned int n, t_returnval *returnval)
{
	char	digit;

	if (n > 9)
	{
		ft_putnbr(n / 10, returnval);
		ft_putnbr(n % 10, returnval);
	}
	else
	{
		digit = n + 48;
		ft_putchar(digit, returnval);
	}
}
