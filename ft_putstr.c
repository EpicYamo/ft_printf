/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:10:14 by aaycan            #+#    #+#             */
/*   Updated: 2024/12/06 01:22:15 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, t_returnval *returnval)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], returnval);
		i++;
	}
}
