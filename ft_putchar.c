/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:08:55 by aaycan            #+#    #+#             */
/*   Updated: 2024/12/06 01:22:13 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putchar(char c, t_returnval *returnval)
{
	if (write(1, &c, 1) == -1)
		returnval->error += 1;
	else
		returnval->error += 0;
}
