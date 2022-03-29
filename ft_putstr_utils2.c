/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:10:49 by npiya-is          #+#    #+#             */
/*   Updated: 2022/03/28 00:31:10 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c);

char	*ft_hextoa(unsigned long long n, int up_or_lo);

char	*ft_utoa(unsigned int n);

size_t	ft_print_plus_or_space(char c)
{
	ft_putchar(c);
	return (1);
}

char	*ft_printf_char(t_format *form, va_list src)
{
	char	*str;
	char	c;

	if (form->type == 'c')
	{
		c = va_arg(src, int);
		ft_putchar(c);
	}
	if (form->type == 's')
	{
		str = va_arg(src, char *);
		if (!str)
			str = "(null)";
		return (ft_strdup(str));
	}
	if (form->type == '%')
		ft_putchar('%');
	return (NULL);
}

char	*ft_printf_integer(t_format *form, va_list src)
{
	long int	i;

	i = 0;
	if (form->type == 'd')
	{
		i = va_arg(src, int);
		return (ft_itoa(i));
	}
	if (form->type == 'i')
	{
		i = va_arg(src, int);
		return (ft_itoa(i));
	}
	return (NULL);
}

char	*ft_printf_hex(t_format *form, va_list src)
{
	long int	u;

	u = 0;
	if (form->type == 'x')
	{
		u = va_arg(src, unsigned int);
		return (ft_hextoa(u, 1));
	}
	if (form->type == 'X')
	{
		u = va_arg(src, unsigned int);
		return (ft_hextoa(u, 0));
	}
	if (form->type == 'u')
	{
		u = va_arg(src, unsigned int);
		return (ft_utoa(u));
	}
	return (NULL);
}
