BIN = libftprintf.a
LIBFT = libft.a
FLAGS = -Wall -Wextra -Werror

INCLUDES = .
SRCS =	ft_printf.c					\
		$(wildcard utilities/*.c)	\
		$(wildcard libft/*.c)

OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	ar rcs $(BIN) $(OBJS) 

main: all
	gcc $(FLAGS) main.c $(BIN) -o output

%.o: %.c
	gcc $(FLAGS) -c -I $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(BIN)

re: fclean all
