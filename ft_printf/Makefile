NAME = libftprintf.a
CC = cc
CCFLAGS = -Wall -Wextra -Werror

FUNCS = ft_printf.c ft_conditions.c ft_functions_first.c ft_functions_sec.c

OBJ = $(FUNCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
