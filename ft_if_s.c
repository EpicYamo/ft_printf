/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:53:12 by aaycan            #+#    #+#             */
/*   Updated: 2024/12/06 01:21:54 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_if_s(char *str, t_returnval *returnval)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", returnval);
		returnval->j += 6;
		return ;
	}
	while (str[i])
	{
		ft_putchar(str[i], returnval);
		i++;
		returnval->j += 1;
	}
}
