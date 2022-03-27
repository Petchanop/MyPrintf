/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:44:04 by npiya-is          #+#    #+#             */
/*   Updated: 2022/03/27 12:02:15 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_convert_args(t_format *form, va_list src);

size_t		ft_putformatstr(char *str, t_format *form);

t_format	*ft_check_type(char *format, t_format *form);

int			ft_check_format(const char c);

void		ft_putchar(char c);

int	ft_print_format(const char *format, t_format *form, va_list src)
{
	char		*str;
	size_t		i;
	int			max;
	int			count;
	t_format	*tmp;

	i = 0;
	max = 0;
	count = 0;
	while (*(format + i) && i < ft_strlen(format))
	{
		if (ft_check_format(*(format + i)) && form)
		{
			str = ft_convert_args(form, src);
			if (str)
				max += ft_putformatstr(str, form);
			if (form->type == 'c')
				max += 1;
			free(str);
			i = form->n + form->len;
			tmp = form;
			form = form->next;
			free(tmp);
		}
		if (!ft_check_format(*(format + i)) && *(format + i))
		{
			count++;
			ft_putchar(*(format + i));
			i++;
		}
	}
	return (max + count);
}
