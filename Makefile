NAME = push_swap

SRC = src/init.c src/butterfly.c src/push_swap.c src/sorting.c \
	src/stack_oper_a.c src/stack_oper_b.c src/utils.c \
	src/utils1.c src/utils2.c src/validation.c

OBJS = $(SRC:.c=.o)

INCLUDES = includes
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES) -I $(LIBFT_DIR)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
	
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re



