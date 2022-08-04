CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = do-op
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re : fclean $(TARGET)
