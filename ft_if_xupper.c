/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_xupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:02:48 by aaycan            #+#    #+#             */
/*   Updated: 2024/12/06 01:22:01 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static char	*ft_to_hex_positive(int num, char *hex);
static char	*ft_to_hex_negative(int num, char *hex);
static int	ft_get_hex_length(int num);

void	ft_if_xupper(int num, t_returnval *returnval)
{
	char	*hex;
	int		i;

	i = 0;
	if (num >= 0)
	{
		hex = (char *)malloc((ft_get_hex_length(num) + 1) * sizeof(char));
		if (!hex)
			return ;
		hex = ft_to_hex_positive(num, hex);
	}
	else
	{
		hex = (char *)malloc(sizeof(char) * 9);
		if (!hex)
			return ;
		hex = ft_to_hex_negative(num, hex);
	}
	while (hex[i])
	{
		returnval->j += 1;
		ft_putchar(hex[i++], returnval);
	}
	free(hex);
}

static char	*ft_to_hex_positive(int num, char *hex)
{
	int		index;
	char	*hex_digits;

	if (num == 0)
	{
		hex[0] = '0';
		hex[1] = '\0';
		return (hex);
	}
	hex_digits = ft_strdup("0123456789ABCDEF");
	index = ft_get_hex_length(num);
	hex[index--] = '\0';
	while (num > 0)
	{
		hex[index--] = hex_digits[num % 16];
		num /= 16;
	}
	free(hex_digits);
	return (hex);
}

static char	*ft_to_hex_negative(int num, char *hex)
{
	unsigned int	n;
	char			*hex_digits;
	int				i;

	hex_digits = ft_strdup("0123456789ABCDEF");
	i = 7;
	hex[8] = '\0';
	n = (unsigned int)num;
	while (n > 0)
	{
		hex[i--] = hex_digits[n % 16];
		n /= 16;
	}
	while (i >= 0)
	{
		hex[i--] = '0';
	}
	free(hex_digits);
	return (hex);
}

static int	ft_get_hex_length(int num)
{
	int	length;

	length = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		length++;
	}
	return (length);
}
