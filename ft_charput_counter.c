/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charput_counter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:36:42 by aaycan            #+#    #+#             */
/*   Updated: 2024/12/13 18:10:11 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_charput_counter(char c, t_returnval *returnval)
{
	if (write(1, &c, 1) == -1)
		returnval->error += 1;
	else
	{
		returnval->error += 0;
		returnval->j += 1;
	}
}
