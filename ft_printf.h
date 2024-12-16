/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:32:07 by aaycan            #+#    #+#             */
/*   Updated: 2024/12/13 17:49:24 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_returnval
{
	int	j;
	int	error;
	int	plus_flag;
	int	hashtag_flag;
	int	space_flag;
}	t_returnval;

int		ft_printf(const char *format, ...);
int		ft_formatspecifier(char *format, va_list *args, int *i,
			t_returnval *returnval);

void	ft_putchar(char c, t_returnval *returnval);
void	ft_putstr(char *str, t_returnval *returnval);
void	ft_charput_counter(char c, t_returnval *returnval);

int		ft_strlen(const char *v);
char	*ft_strdup(const char *s1);
void	ft_check_edge_cases(char *format, va_list *args, int *i,
			t_returnval *returnval);

void	ft_if_s(char *str, t_returnval *returnval);
void	ft_if_c(char c, t_returnval *returnval);
void	ft_if_p(void *address, t_returnval *returnval);
void	ft_if_iord(int n, t_returnval *returnval);
void	ft_if_pe(t_returnval *returnval);
void	ft_if_u(unsigned int n, t_returnval *returnval);
void	ft_if_xlower(int num, t_returnval *returnval);
void	ft_if_xupper(int num, t_returnval *returnval);

#endif
