/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:58:18 by npiya-is          #+#    #+#             */
/*   Updated: 2022/03/18 19:00:38 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_format
{
	int	n;
	int	len;
	int	para;
	int	width;
	int	pre;
	char	flag;
	char	type;
	struct s_format	*next;
}	t_format;

int	ft_printf(const char *format, ...);

#endif
