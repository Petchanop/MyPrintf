/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:15:29 by npiya-is          #+#    #+#             */
/*   Updated: 2022/03/20 00:01:47 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ctoa(char ch)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	str[0] = ch;
	str[1] = 0;
	return (str);
}

static char	*ft_convert(unsigned int n, int digit, char *str)
{
	while (digit)
	{
		str[digit - 1] = (n % 10) + '0';
		n /= 10;
		digit--;
	}
	return (str);
}

char	*ft_utoa(unsigned int n)
{
	long	i;
	int		j;
	char	*str;

	i = 10;
	j = 1;
	while (n / i)
	{
		i *= 10;
		j++;
	}
	str = malloc((j + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	str[j] = '\0';
		str = ft_convert(n, j, str);
	return (str);
}

static char	*ft_convert_p(size_t n, int digit, char *str)
{
	char	*hex;

	hex = "0123456789abcdef";
	while (digit)
	{
		str[digit + 1] = hex[(n % 16)];
		n /= 16;
		digit--;
	}
	return (str);
}

char	*ft_ptoa(void *ptr)
{
	size_t	n;
	size_t	i;
	int		j;
	char	*str;

	i = 16;
	j = 1;
	n = (size_t)ptr;
	while (n / i)
	{
		i *= 16;
		j++;
	}
	str = malloc((j + 3) * sizeof(char));
	if (!(str))
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	str[j + 2] = '\0';
	str = ft_convert_p(n, j, str);
	return (str);
}
