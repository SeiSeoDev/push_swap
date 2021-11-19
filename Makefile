
CC = clang

NAME = push_swap

LIBFT = libft

DIR_S = srcs/

HEADER = includes/

SOURCES =	pushswap.c	\
			actions.c	\
			actions2.c	\
			actions3.c	\
			radix.c		\
			sort.c		\
			utils.c

SRCS = $(addprefix $(DIR_S),$(SOURCES))

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I $(HEADER)

FLAGS = -L $(LIBFT) -lft

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(FLAGS) -o $(NAME)

norme:
	norminette ./$(LIBFT)
	@echo
	norminette ./$(HEADER)
	@echo
	norminette ./$(DIR_S)

bonus: all

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all