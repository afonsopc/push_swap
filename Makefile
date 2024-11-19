NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = args.c error.c numbers.c numbers2.c \
	push.c rotate.c swap.c reverse_rotate.c \
	radix_sort.c test_sort.c utils.c utils2.c \
	main.c
OBJ = $(SRC:.c=.o)
OBJDIR = obj/
OBJS = $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re