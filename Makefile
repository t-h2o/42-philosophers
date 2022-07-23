#	Compilation setting

NAME	=	philo

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
CLIB	=	-lpthread -L libft -lft
#OFLAGS	=	-fsanitize=address


#	Headers

DIR_INC	=	./headers/
HEADER	+=	philo.h
HEADER	+=	libft.h


#	Sources

DIR_SRC	=	./srcs
SRCS	=	$(DIR_SRC)/main.c	\
			$(DIR_SRC)/time.c	\
			$(DIR_SRC)/parse.c	\
			$(DIR_SRC)/brexit.c	\
			$(DIR_SRC)/thread.c	\
			$(DIR_SRC)/message.c


#	Objets

DIR_OBJ =	./objs
OBJS	=	$(addprefix $(DIR_OBJ)/, $(notdir $(SRCS:.c=.o)))

RM		=	rm -rf

vpath %.c $(DIR_SRC)


all : $(NAME)

$(NAME):	$(OBJS)
	make -C libft/ --silent
	$(CC) $(OFLAGS) $(OBJS) $(CLIB) -o $(NAME)

$(DIR_OBJ)/%.o : %.c | $(DIR_OBJ)
	$(CC) $(CFLAGS) -I $(DIR_INC) -o $@ -c $^

$(DIR_OBJ) :
	@mkdir -p $(DIR_OBJ)

clean:
	make -C libft/ clean --silent
	$(RM) $(DIR_OBJ)

fclean: clean
	make -C libft/ fclean --silent
	$(RM) $(NAME)

re:	fclean all

norm:
	clear
	@(norminette ${DIR_INC}${HEADER} ${SRCS} | grep -v  OK\!) || true

lldb:
	gcc $(SRCS) -I $(DIR_INC) -g -o $(NAME)
	lldb $(NAME)

