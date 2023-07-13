NAME=	libftprintf.a

SRC=	ft_printf.c\
		printf_utils.c\
		printf_hex.c

OBJ=	$(subst .c,.o,$(SRC))

CC=		gcc
CFLAGS=	-g -Wall -Wextra -Werror -I../ft_printf

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib	$(NAME)

test: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)

%.o: %.c
	$(CC) -c $^ -o $@ $(CFLAGS)

clean:
	rm -f *.o

fclean: clean
	rm -f ./a.out $(NAME)

re: fclean all

.PHONY: all clean fclean re
