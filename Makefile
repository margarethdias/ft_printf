NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =  	src/*.c

OBJS = $(SRC:%.c=%.o)

# B_SRCS =


B_OBJS = $(B_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

bonus: $(B_OBJS)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
