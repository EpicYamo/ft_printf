/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatspecifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:41:08 by aaycan            #+#    #+#             */
/*   Updated: 2024/12/13 17:47:04 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatspecifier(char *f, va_list *args, int *i, t_returnval *returnval)
{
	if (f[0] == '%')
		ft_if_pe(returnval);
	else if ((f[0] == 'd' || f[0] == 'i') && *args)
		ft_if_iord(va_arg(*args, int), returnval);
	else if (f[0] == 'u')
		ft_if_u(va_arg(*args, unsigned int), returnval);
	else if (f[0] == 'x')
		ft_if_xlower(va_arg(*args, int), returnval);
	else if (f[0] == 'X')
		ft_if_xupper(va_arg(*args, int), returnval);
	else if (f[0] == 's')
		ft_if_s(va_arg(*args, char *), returnval);
	else if (f[0] == 'c')
		ft_if_c(va_arg(*args, int), returnval);
	else if (f[0] == 'p')
		ft_if_p(va_arg(*args, void *), returnval);
	else if (f[0] == '\0')
		return (-1);
	else if (f[0] == ' ' || f[0] == '0' || f[0] == '-'
		|| f[0] == '+' || f[0] == '#')
		ft_check_edge_cases(&f[0], args, i, returnval);
	else
		returnval->error += 1;
	return (returnval->j);
}
