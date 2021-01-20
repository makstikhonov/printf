# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: max <max@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 17:05:38 by max               #+#    #+#              #
#    Updated: 2021/01/19 10:36:04 by max              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		ft_if_percent.c \
		ft_flags.c \
		ft_itoa_base.c \
		ft_if_c.c \
		ft_if_s.c \
		ft_if_p.c \
		ft_if_u.c \
		ft_if_i.c \
		ft_if_i_if.c \
		ft_if_x.c \
		ft_if_x_lower.c \
		ft_parse_str.c \
		ft_flag_parse.c \
		ft_type.c \
		ft_print.c

SRCS_O = 	ft_printf.o \
			ft_if_percent.o \
			ft_flags.o \
			ft_itoa_base.o \
			ft_if_c.o \
			ft_if_s.o \
			ft_if_p.o \
			ft_if_u.o \
			ft_if_i.o \
			ft_if_i_if \
			ft_if_x.o \
			ft_if_x_lower.o \
			ft_parse_str.o \
			ft_flag_parse.o \
			ft_type.o \
			ft_print.o

CC = gcc

FLAGS = -c -Wall -Wextra -Werror 

INCLUDES = -I./

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SRCS_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
