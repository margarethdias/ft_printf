NAME=libftprintf.a
SRC=ft_printf.c
OBJ=$(SRC:.c=.o)
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
    ar rcs $(NAME) $(OBJ)

%.o: %.c
    gcc $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re: fclean all
