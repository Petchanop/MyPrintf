/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:43:42 by npiya-is          #+#    #+#             */
/*   Updated: 2022/03/27 12:18:22 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_putstr(char *str, size_t index)
{
	size_t	i;

	i = 0;
	while (*(str + index))
	{
		ft_putchar(*(str + index));
		index++;
		i++;
	}
	return (i);
}

size_t	ft_printf_para(char *str, char ch, t_format *form)
{
	size_t	len;

	len = 0;
	while (form->para > (int)ft_strlen(str))
	{
		ft_putchar(ch);
		form->para--;
		len++;
	}
	return (len);
}

size_t	ft_printf_sign(char *str, t_format *form)
{
	size_t	i;

	i = 0;
	if (*str == '-')
	{
		if (form->pre)
			form->para += 1;
		ft_putchar(*str);
		i++;
	}
	return (i);
}

size_t	ft_printf_bypara(char *str, t_format *form)
{
	size_t	i;

	i = 0;
	while (form->para && *(str + i))
	{
		ft_putchar(*(str + i));
		form->para--;
		i++;
	}
	return (i);
}
