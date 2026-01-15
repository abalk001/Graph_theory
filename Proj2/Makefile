NAME = er_graph

SRC = srcs/er_graph.c srcs/tools.c srcs/graph.c 
OBJS = $(SRC:.c=.o)
RM = rm -f
CC = cc 
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: 
	$(RM) $(NAME)

re : fclean all
.PHONY: all re fclean all
