CC = gcc
CFLAGS = -Wall -Wextra -Werror

INC = includes
SRC = srcs

TARGET = libft.a

SOURCES = $(SRC)/ft_putchar.c $(SRC)/ft_swap.c $(SRC)/ft_putstr.c $(SRC)/ft_strlen.c $(SRC)/ft_strcmp.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	ar -rc $@ $^

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

clean: 
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re : fclean all
