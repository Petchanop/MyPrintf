/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:02:46 by npiya-is          #+#    #+#             */
/*   Updated: 2022/03/27 12:35:54 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ctoa(char ch);

char	*ft_utoa(unsigned int n);

char	*ft_ptoa(unsigned long long n);

size_t	ft_printf_para(char *str, char ch, t_format *form);

size_t	ft_printf_sign(char *str, t_format *form);

size_t	ft_printf_bypara(char *str, t_format *form);

void	ft_putchar(char c);

size_t	ft_putstr(char *stri, size_t index);

size_t	ft_printf_hash(t_format *form)
{
	char	*hex;
	char	*x;
	char	*hash;

	hex = "0X";
	x = "0x";
	hash = NULL;
	if (form->flag == '#')
	{
		if (form->type == 'x')
			hash = x;
		if (form->type == 'X')
			hash = hex;
	}
	if (hash)
	{
		while (*hash)
			ft_putchar(*hash++);
		return (2);
	}
	return (0);
}

size_t	ft_putformatstr(char *str, t_format *form)
{
	size_t	i;
	size_t	len;
	char	ch;

	i = 0;
	len = 0;
	if (form->flag == '0' || form->pre)
		ch = '0';
	if (form->flag == '+' && *str != '-')
	{
		ch = '+';
		ft_putchar(ch);
		len++;
	}
	if (form->para && form->type != 's')
	{
		i = ft_printf_sign(str, form);
		len += ft_printf_para(str, ch, form);
	}
	if (form->type == 's' && form->pre == 1)
	{
		i = ft_printf_bypara(str, form);
		return (len + i);
	}
	if (*str != '0' && form->flag == '#')
		len += ft_printf_hash(form);
	i += ft_putstr(str, i);
	return (len + i);
}

char	*ft_convert_hex(long long n, int digit, char *str, int up_or_lo)
{
	char	*hex;
	char	*lower;
	char	*upper;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	if (n == 0)
		str[0] = '0';
	if (up_or_lo)
		hex = lower;
	else
		hex = upper;
	while (digit)
	{
		str[digit - 1] = hex[(n % 16)];
		n /= 16;
		digit--;
	}
	return (str);
}

char	*ft_hextoa(unsigned long long n, int up_or_lo)
{
	unsigned long long	i;
	int					j;
	char				*str;

	i = n / 16;
	j = 1;
	while (i)
	{
		i /= 16;
		j++;
	}
	if (n < 0)
		j += 1;
	str = malloc((j + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n >= 0)
		str = ft_convert_hex(n, j, str, up_or_lo);
	else
	{
		str = ft_convert_hex(n, j, str, up_or_lo);
		str[0] = '-';
	}
	str[j] = 0;
	return (str);
}

char	*ft_convert_args(t_format *form, va_list src)
{
	unsigned char	*ptr;
	char			*str;
	char			c;
	long int		i;
	long int		u;

	u = 0;
	i = 0;
	if (form->type == 'c')
	{
		c = va_arg(src, int);
		ft_putchar(c);
		return (NULL);
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
