NAME = barabasi_Albert 
SRC = srcs/er_graph.c srcs/tools.c srcs/utils.c srcs/graph_tools.c \
      srcs/degree_distribution.c  main.c 
OBJS = $(SRC:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lm
RM = rm -f

all : $(NAME) clean

$(NAME) : $(OBJS)
	 $(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

%.o:%.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	 $(RM) $(OBJS)

fclean : clean 
	$(RM) $(NAME)

re : fclean  all

run : 
	./$(NAME) 4

.PHONY : fclean clean re all
