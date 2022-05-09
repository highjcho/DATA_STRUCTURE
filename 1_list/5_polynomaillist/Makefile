CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = polynomiallist

SRCS = poly_main.c polynomiallist.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

clean :
	rm -rf *.o
	rm -rf $(NAME)

