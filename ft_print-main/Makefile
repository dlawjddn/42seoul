NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a

SRCS = ./ft_printf.c ./ft_format.c ./ft_parse.c ./ft_print_chars.c ./ft_print_hex.c ./ft_print_nbrs.c ./ft_print_point.c ./ft_print_utils.c
OBJS = $(SRCS:.c=.o)
INCS = .
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME): $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

bonus: $(NAME)

re: fclean all

.PHONY: all clean fclean re
