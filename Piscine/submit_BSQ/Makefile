CC = gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= BSQ
SRC_DIR = ./srcs
HD_DIR = ./includes
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/make_map.c $(SRC_DIR)/print_map.c $(SRC_DIR)/print_map_sub.c
OBJS = $(SRCS:.c=.o)

all :	$(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HD_DIR)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY:all clean fclean re
