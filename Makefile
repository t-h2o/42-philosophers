#	Compilation setting

NAME	=	philo

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
CLIB	=	-lpthread -L libft -lft
#OFLAGS	=	-fsanitize=address


#	Headers

INCD	=	./headers

INCS	=	$(INCD)/philo.h
INCS	+=	$(INCD)/libft.h


#	Sources

SRCD	=	./srcs

SRCS	=	$(SRCD)/main.c
SRCS	+=	$(SRCD)/time.c
SRCS	+=	$(SRCD)/parse.c
SRCS	+=	$(SRCD)/brexit.c
SRCS	+=	$(SRCD)/thread.c
SRCS	+=	$(SRCD)/message.c


#	Objets

OBJD	=	./objs
OBJS	=	$(addprefix $(OBJD)/, $(notdir $(SRCS:.c=.o)))

RM		=	rm -rf

vpath %.c $(SRCD)


all : $(NAME)

$(NAME):	$(OBJS)
	make -C libft/ --silent
	$(CC) $(OFLAGS) $(OBJS) $(CLIB) -o $(NAME)

$(OBJD)/%.o : %.c | $(OBJD)
	$(CC) $(CFLAGS) -I $(INCD) -o $@ -c $^

$(OBJD) :
	@mkdir -p $(OBJD)

clean:
	make -C libft/ clean --silent
	$(RM) $(OBJD)

fclean: clean
	make -C libft/ fclean --silent
	$(RM) $(NAME)

re:	fclean all


norm:
	clear
	@(norminette $(INCS) $(SRCS) | grep -v  OK\!) || true

lldb:
	gcc $(SRCS) -I $(INCD) -g -o $(NAME)
	lldb $(NAME)

