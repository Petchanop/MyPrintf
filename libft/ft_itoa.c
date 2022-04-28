/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:30:30 by npiya-is          #+#    #+#             */
/*   Updated: 2022/03/23 21:19:20 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_neg(long long n, int digit, char *str)
{
	while (digit > 0)
	{
		str[digit - 1] = '0' - (n % 10);
		n /= 10;
		digit--;
	}
	return (str);
}

char	*ft_convert(long long n, int digit, char *str)
{
	while (digit)
	{
		str[digit - 1] = (n % 10) + '0';
		n /= 10;
		digit--;
	}
	return (str);
}

char	*ft_itoa(long long n)
{
	long long	num;
	int		j;
	char	*str;

	j = 1;
	num = n;
	while (n /= 10)
		j++;
	if (num < 0)
		j += 1;
	str = malloc((j + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	str[j] = '\0';
	if (num >= 0)
		str = ft_convert(num, j, str);
	else
	{
		str = ft_convert_neg(num, j, str);
		str[0] = '-';
	}
	return (str);
}
/*
#include <string.h>

int	main(void)
{
	printf("%s\n",ft_itoa(-2147483648));
	printf("%s\n",ft_itoa(-1000235));
	printf("%s\n",ft_itoa(-14586));
	printf("%s\n",ft_itoa(-1010));
	printf("%s\n",ft_itoa(-1));
	printf("%s\n",ft_itoa(0));
	printf("%s\n",ft_itoa(10));
	printf("%s\n",ft_itoa(1010));
	printf("%s\n",ft_itoa(1005000));
	printf("%s\n",ft_itoa(2147483647));
	return (0);
}
*/
