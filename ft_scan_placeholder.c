/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan_palceholder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:26:30 by npiya-is          #+#    #+#             */
/*   Updated: 2022/03/20 18:53:25 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

# define form_len 5

int	ft_check_precision(const char c);

int     ft_check_widthf(const char c);

int     ft_flags_format(const char c);

int     ft_check_para(const char c, const char dsign);

int     ft_check_format(const char c);

void	ft_assign_format(const char *format, t_format *form)
{
	int	i;

	i = 0;
	if (form->type && form->type != '%')
	{
		while (i < form_len && *(format + i) != form->type)
		{
			if (ft_check_para(*(format + i), *(format + i + 1)))
				form->para = ft_atoi(format);
			if (ft_flags_format(*(format + i)))
				form->flag = *format;
			if (ft_check_precision(*(format + i)))
				form->pre = 1;
			if (ft_check_widthf(*(format + i)))
				form->width = 1;
			i++;
		}
	}
	else
		return ;
}

void	ft_assign_type(char type, t_format *form)
{
		if (type == 'c')
			form->type = 'c';
		if (type == 's')
			form->type = 's';
		if (type == 'd')
			form->type = 'd';
		if (type == 'p')
			form->type = 'p';
		if (type == 'i')
			form->type = 'i';
		if (type == 'u')
			form->type = 'u';
		if (type == 'x')
			form->type = 'x';
		if (type == 'X')
			form->type = 'X';
		if (type == '%')
			form->type = '%';
		else
			return ;
}

t_format	*ft_check_type(const char *format, t_format *form)
{
	int	format_len;

	format_len = 0;
	while (*(format + format_len) && format_len < form_len)
	{
		ft_assign_type(*(format + format_len), form);
		if (form->type)
			break;
		format_len++;
	}
	form->len = format_len + 1;
	ft_assign_format(format , form);
	return (form);
}
