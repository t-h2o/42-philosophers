#	Compilation setting

NAME	=	philo

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
#OFLAGS	=	-fsanitize=address


#	Headers

DIR_INC	=	./headers/
HEADER	=	philo.h


#	Sources

DIR_SRC	=	./srcs
SRCS	=	$(DIR_SRC)/main.c	\
			$(DIR_SRC)/time.c	\
			$(DIR_SRC)/thread.c


#	Objets

DIR_OBJ =	./objs
OBJS	=	$(addprefix $(DIR_OBJ)/, $(notdir $(SRCS:.c=.o)))

RM		=	rm -rf

vpath %.c $(DIR_SRC)


all : $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OFLAGS) $(OBJS) -o $(NAME)

$(DIR_OBJ)/%.o : %.c | $(DIR_OBJ)
	$(CC) $(CFLAGS) -I $(DIR_INC) -o $@ -c $^

$(DIR_OBJ) :
	@mkdir -p $(DIR_OBJ)

clean:
	$(RM) $(DIR_OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

norm:
	norminette $(SRCS)
	norminette $(HEADER)

lldb:
	gcc $(SRCS) -I $(DIR_INC) -g -o $(NAME)
	lldb $(NAME)

