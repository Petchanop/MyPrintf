/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:43:42 by npiya-is          #+#    #+#             */
/*   Updated: 2022/03/28 00:41:00 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_data(t_format	*format);

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

size_t	ft_putstr(char *str, size_t index, t_format *form)
{
	size_t	i;

	i = 0;

	
	if (form->width < 0)
		form->width *= -1;;
	//printf("%zu\n", index);
	ft_print_data(form);
	if (form->width > form->para && *str == '0' && form->pre && form->para == 0)
		return (i);
	if (*str == '0' && form->pre && !form->para && !form->width)
		return (i);
	while (*(str + index))
	{
		ft_putchar(*(str + index));
		index++;
		i++;
	}
	return (i);
}

size_t	ft_printf_pre(char *str, t_format *form)
{
	size_t	i;
	int	para;

	i = 0;
	para = 0;
	//ft_print_data(form);
	if (form->flag != '-')
	{
		if (form->para > (int)ft_strlen(str))
		{
			para += form->para;
			if (*str == '-')
				para++;
		}
		else if (*str != '0')
			para += (int)ft_strlen(str);
		else if (*str == '0' && form->para)  
			para += 1;
		else if (*str == '0' && form->width && !form->flag)
			para += ft_strlen(str);
		//printf("%d, %d\n", form->width, para);
		while (form->width - (int)i > para)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (i);
}

size_t	ft_printf_para(char *str, char ch, t_format *form)
{
	size_t	len;

	len = 0;
	if (!ch)
		return (len);
	while (form->para  - (int)len > (int)ft_strlen(str))
	{
		ft_putchar(ch);
		len++;
	}
	return (len);
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
