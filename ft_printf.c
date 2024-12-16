/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:34:39 by aaycan            #+#    #+#             */
/*   Updated: 2024/12/13 17:46:33 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_setvars(int *i, t_returnval *returnval);
static int	ft_returnval_func(t_returnval *returnval);

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_returnval	returnval;
	int			i;

	if (!format)
		return (-1);
	va_start(args, format);
	ft_setvars(&i, &returnval);
	while (format[i])
	{
		if (format[i] == '%')
		{
			returnval.j = ft_formatspecifier((char *)&format[i + 1], &args, &i,
					&returnval);
			if (returnval.j == -1)
				return (-1);
			i += 2;
		}
		else
			ft_charput_counter(format[i++], &returnval);
	}
	va_end(args);
	return (ft_returnval_func(&returnval));
}

static void	ft_setvars(int *i, t_returnval *returnval)
{
	*i = 0;
	returnval->j = 0;
	returnval->error = 0;
	returnval->space_flag = 0;
	returnval->plus_flag = 0;
	returnval->hashtag_flag = 0;
}

static int	ft_returnval_func(t_returnval *returnval)
{
	if (returnval->error != 0)
		return (-1);
	else
		return (returnval->j);
}
