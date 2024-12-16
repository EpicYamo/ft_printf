/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_iord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:48:37 by aaycan            #+#    #+#             */
/*   Updated: 2024/12/16 15:30:33 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int n, t_returnval *returnval);
static void	ft_set_bonus_iord(int n, t_returnval *returnval);

void	ft_if_iord(int n, t_returnval *returnval)
{
	ft_set_bonus_iord(n, returnval);
	ft_putnbr(n, returnval);
	if (n == 0)
		returnval->j += 1;
	else if (n == -2147483648)
		returnval->j += 11;
	else if (n > 0)
	{
		while (n > 0)
		{
			returnval->j += 1;
			n = n / 10;
		}
	}
	else if (n < 0)
	{
		returnval->j += 1;
		n = -n;
		while (n > 0)
		{
			returnval->j += 1;
			n = n / 10;
		}
	}
}

static void	ft_putnbr(int n, t_returnval *returnval)
{
	char	digit;

	if (n == -2147483648)
		ft_putstr("-2147483648", returnval);
	else if (n < 0)
	{
		ft_putchar('-', returnval);
		n = -n;
		ft_putnbr(n, returnval);
	}
	else
	{
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
}

static void	ft_set_bonus_iord(int n, t_returnval *returnval)
{
	if (n >= 0)
	{
		if ((returnval->space_flag == 1) || (returnval->plus_flag == 1))
		{
			if (returnval->plus_flag == 1)
				ft_charput_counter('+', returnval);
			else if (returnval->space_flag == 1)
				ft_charput_counter(' ', returnval);
		}
	}
}
