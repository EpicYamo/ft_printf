/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_edge_cases.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:44:39 by aaycan            #+#    #+#             */
/*   Updated: 2024/12/13 18:26:21 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_flags(char *f, t_returnval *returnval);
static void	ft_hashtag(char *f, t_returnval *returnval);

void	ft_check_edge_cases(char *f, va_list *args, int *i,
		t_returnval *returnval)
{
	int	c;

	c = 0;
	while (f[c] == ' ' || f[c] == '+' || f[c] == '#'
		|| f[c] == '0' || f[c] == '-')
	{
		if (f[c] == '+' || f[c] == ' ' || f[c] == '#')
			ft_check_flags(&f[c], returnval);
		c++;
		*i += 1;
	}
	ft_hashtag(&f[c], returnval);
	ft_formatspecifier(&f[c], args, i, returnval);
}

static void	ft_check_flags(char *f, t_returnval *returnval)
{
	if (f[0] == ' ')
		returnval->space_flag = 1;
	if (f[0] == '+')
		returnval->plus_flag = 1;
	if (f[0] == '#')
		returnval->hashtag_flag = 1;
}

static void	ft_hashtag(char *f, t_returnval *returnval)
{
	if (returnval->hashtag_flag == 1)
	{
		if (f[0] == 'x')
		{
			ft_charput_counter('0', returnval);
			ft_charput_counter('x', returnval);
		}
		else if (f[0] == 'X')
		{
			ft_charput_counter('0', returnval);
			ft_charput_counter('X', returnval);
		}
	}
}
