/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:02:46 by npiya-is          #+#    #+#             */
/*   Updated: 2022/03/20 19:05:53 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ctoa(char ch);

char	*ft_utoa(unsigned int n);

char	*ft_ptoa(unsigned long long n);

void	ft_putchar(char c)
{
	if (c)
		write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
	{
		ft_putchar(*(str + i));
		i++;
	}
}

char	*ft_convert_hex(long long n, int digit, char *str,int up_or_lo)
{
	char	*hex;
	char	*lower;
	char	*upper;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (up_or_lo)
		hex = lower;
	else
		hex = upper;
	while (n)
	{
		str[digit - 1] = hex[(n % 16)];
		n /= 16;
		digit--;
	}
	return (str);
}

char	*ft_hextoa(long long n, int up_or_lo)
{
	long long	i;
	int		j;
	char	*str;

	i = 16;
	j = 1;
	while (n / i)
	{
		i *= 16;
		j++;
	}
	if (n < 0)
		j += 1;
	str = ft_calloc(1, j + 1);
	if (n >= 0)
		str = ft_convert_hex(n, j, str, up_or_lo);
	else
	{
		str = ft_convert_hex(n, j, str, up_or_lo);
		str[0] = '-';
	}
	return (str);
}

char	*ft_convert_args(t_format *form, va_list src)
{
	char	*str;
	char	c;
	int	i;
	long int	u;
	unsigned char	*ptr;

	u = 0;
	i = 0;
	if (form->type == 'c')
	{
		c = va_arg(src, int);
		ft_putchar(c);
		return NULL;
	}
	if (form->type == 's')
	{
		str = va_arg(src, char *);
		if (!str)
			str = "(null)";
		return (ft_strdup(str));
	}
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
	if (form->type == 'u')
	{
		u = va_arg(src, unsigned int);
		return (ft_utoa(u));
	}
	if (form->type == 'p')
	{
		ptr = (unsigned char *)va_arg(src, void *);
		return (ft_ptoa((unsigned long long)ptr));
	}
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
	if (form->type == '%')
	{
		c = '%';
		return (ft_ctoa(c));
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%s\n", ft_hextoa(26, 0));
	printf("%s\n", ft_hextoa(321, 0));
	printf("%s\n", ft_hextoa(1234, 1));
	printf("%s\n", ft_hextoa(12345, 0));
	printf("%s\n", ft_hextoa(789653, 1));
	printf("%s\n", ft_hextoa(6725624, 0));
	printf("%s\n", ft_hextoa(82938725, 1));
}*/
