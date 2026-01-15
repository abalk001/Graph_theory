NAME = basic

SRC = srcs/graph.c srcs/main.c

CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	
fclean: clean 
	$(RM) $(NAME)

re : fclean all 
.PHONY: re all clean fclean
