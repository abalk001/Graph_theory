NAME = baraski_Albert 
SRC = srcs/er_graph.c srcs/tools.c srcs/utils.c srcs/graph_tools.c main.c 
OBJS = $(SRC:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(NAME) clean

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS)

fclean : clean 
	$(RM) $(NAME)

re : fclean  all

.PHONY : fclean clean re all
