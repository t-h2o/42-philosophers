#	Compilation setting

NAME	=	philo

CC		=	gcc
DB		=	lldb
LIBFTD	=	42-libft

CFLAGS	=	-Wall
CFLAGS	+=	-Wextra
CFLAGS	+=	-Werror
CFLAGS	+=	-g

OFLAGS	=	-fsanitize=address

CLIB	=	-lpthread -L $(LIBFTD) -lft
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
	make -C $(LIBFTD)/ --silent
	$(CC) $(OFLAGS) $(OBJS) $(CLIB) -o $(NAME)

$(OBJD)/%.o : %.c | $(OBJD)
	$(CC) $(CFLAGS) -I $(INCD) -o $@ -c $^

$(OBJD) :
	@mkdir -p $(OBJD)

clean:
	make -C $(LIBFTD)/ clean --silent
	$(RM) $(OBJD)

fclean: clean
	make -C $(LIBFTD)/ fclean --silent
	$(RM) $(NAME)

re:	fclean all


norm:
	clear
	@(norminette $(INCS) $(SRCS) | grep -v  OK\!) || true

db: all
	${DB} $(NAME)
