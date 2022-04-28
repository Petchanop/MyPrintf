# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 17:56:41 by npiya-is          #+#    #+#              #
#    Updated: 2022/04/28 19:52:49 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c \
       ft_printf_format.c \
       ft_printf_format2.c \
       ft_printf_utils.c \
       ft_printf_utils2.c \
       ft_format_placeholder.c \
       ft_scan_placeholder.c \
       ft_putstr_utils.c \
       ft_putstr_utils2.c \

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

LIBC = libft.a

all:$(NAME)

.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):$(OBJS)
	@make -C libft/
	@ar -x libft/$(LIBC)
	@ar rcs $(NAME) $(OBJS) *.o


bonus: all

clean:
	@rm -rf $(OBJS) *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
