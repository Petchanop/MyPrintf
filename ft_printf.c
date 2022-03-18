/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:57:56 by npiya-is          #+#    #+#             */
/*   Updated: 2022/03/18 01:25:21 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_args(t_format *form, va_list src);

int	ft_check_format(const char c);

t_format	*ft_check_type(char *format, t_format *form);

void	ft_putstr(char *str);

void	ft_print_data(t_format	*format)
{
	while (format)
	{
		printf("form_data->n   : %d\n", format->n);
        	printf("form_data->len : %d\n", format->len);
        	printf("form_data->p   : %d\n", format->para);
        	printf("form_data->w   : %d\n", format->width);
        	printf("form_data->pr  : %d\n", format->pre);
        	printf("form_data->f   : %c\n", format->flag);
        	printf("form_data->t   : %c\n", format->type);
		format = format->next;
	}
}

size_t	ft_count_sign(t_format *format)
{
	t_format	*tmp;
	size_t	i;

	tmp = format;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
		

void	ft_addformat(t_format **form_data, t_format *form)
{
	t_format	*temp;

	if (*form_data)
	{
		temp = *form_data;
		while (temp->next)
			temp = temp->next;
		temp->next = form;
		form_data = &temp;
	}
	else
		*form_data = form;
}

void	ft_newformat(t_format *new)
{
	new->n = 0;
	new->len = 0;
	new->para = 0;
	new->width = 0;
	new->pre = 0;
	new->flag = 0;
	new->type = 0;
	new->next = 0;
}

t_format	*ft_create_format(const char *format)
{
	static t_format	*form;
	static t_format	*form_data;
	char	*ptr;
	int	i;

	i = 0;
	ptr = (char *)format;
	//form_data = malloc(sizeof(t_format));
	form_data = NULL;
	while (*(ptr + i))
	{
		if (ft_check_format(*(ptr + i)))
		{
			i++;
			form = malloc(sizeof(t_format));
			ft_newformat(form);
			ft_check_type((ptr + i), form);
			form->n = i;
			ft_addformat(&form_data, form);
		}
		i++;
	}
//	ft_print_data(form_data);
	return (form_data);
}

int	ft_printf(const char *format, ...)
{
	va_list src;
	int	args;
	size_t	max;
	size_t	i;
	t_format	*form;
	t_format	*tmp;
	char	*str;

	args = 0;
	i = 0;
	form = ft_create_format(format);
	max = ft_count_sign(form);
	va_start(src, format);
	while (*(format + i))
	{
		if (ft_check_format(*(format + i)) && form)
		{
			if (form)
			{
				str = ft_convert_args(form, src);
				ft_putstr(str);
				free(str);
				i += (form->len + 1);
				tmp = form;
				form = form->next;
				free(tmp);
			}
		}
		write(1, &*(format + i), 1);
		i++;
	}
	//va_copy(dest, src);
/*	while (form)
	{
			str = ft_convert_args(form, src);
			ft_putstr(str);
			form = form->next;
	}
	printf("\n");
*/	va_end(src);

	return (max);
}

int	main(void)
{
	int	i = 1;
	long	j = 134;
	long	a = 65789;
	char	*str;

	str = "arrrrt";
	ft_printf("test %d %s\n", i, str);
	ft_printf("test %x %s\n", j, str);
	ft_printf("test %d %p\n", i, a);
}
