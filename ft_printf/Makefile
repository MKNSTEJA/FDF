# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 15:14:25 by kmummadi          #+#    #+#              #
#    Updated: 2024/11/22 22:30:44 by kmummadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SCRS = find_specifier.c ft_printf.c ft_putchar.c ft_putstr.c \
       ft_utoa_hex.c ft_utoa.c print_char.c print_hexa.c print_num.c \
       print_pointer.c print_str.c print_unsigned.c
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SCRS:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)
	

$(NAME): $(OBJ) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re