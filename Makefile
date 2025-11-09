NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

LIBFT_DIR   = lib/libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        =	main.c \
				src/parsing/parse.c \
				src/parsing/validate.c \
				src/error.c \
				src/utils/memory.c \
				src/stack/stack_init.c \
				src/stack/stack_check.c \

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
