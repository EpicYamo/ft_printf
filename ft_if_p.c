/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:50:52 by aaycan            #+#    #+#             */
/*   Updated: 2024/12/11 14:37:16 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>

static void	ft_pointer_val_to_hex(unsigned long long n, t_returnval *returnval);

void	ft_if_p(void *address, t_returnval *returnval)
{
	unsigned long long	addr;

	if (address == NULL)
	{
		ft_putstr("(nil)", returnval);
		returnval->j += 5;
	}
	else
	{
		addr = (unsigned long long)address;
		ft_putstr("0x", returnval);
		returnval->j += 2;
		ft_pointer_val_to_hex(addr, returnval);
	}
}

static void	ft_pointer_val_to_hex(unsigned long long n, t_returnval *returnval)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (n > 15)
		ft_pointer_val_to_hex((n / 16), returnval);
	ft_putchar(hex_digits[(n % 16)], returnval);
	returnval->j += 1;
}
