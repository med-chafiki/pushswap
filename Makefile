CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = pushswap.c tools1.c tools.c ft_strjoin.c ft_split.c ft_atoi.c linkedlists.c tools2.c tools3.c tools4.c tools5.c a_instructions.c b_instructions.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re