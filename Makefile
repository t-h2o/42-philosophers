#	Compilation setting

NAME	=	philo

CC		=	gcc
DB		=	lldb

CFLAGS	=	-Wall
CFLAGS	+=	-Wextra
CFLAGS	+=	-Werror
CFLAGS	+=	-g

# Selection fsanitize

## Thread
CFLAGS	+=	-fsanitize=thread
OFLAGS	=	-fsanitize=thread

## Address
#OFLAGS	=	-fsanitize=address


CLIB	=	-lpthread
#OFLAGS	=	-fsanitize=address


#	Headers

INCD	=	./headers

INCS	=	$(INCD)/philo.h


#	Sources

SRCD	=	./srcs

SRCS	=	$(SRCD)/main.c
SRCS	+=	$(SRCD)/end_philo.c
SRCS	+=	$(SRCD)/error.c
SRCS	+=	$(SRCD)/message.c
SRCS	+=	$(SRCD)/parsing.c
SRCS	+=	$(SRCD)/start_philo.c
SRCS	+=	$(SRCD)/time.c
SRCS	+=	$(SRCD)/utils_str.c


#	Objets

OBJD	=	./objs
OBJS	=	$(addprefix $(OBJD)/, $(notdir $(SRCS:.c=.o)))

RM		=	rm -rf

vpath %.c $(SRCD)


all : $(NAME)

$(NAME):	$(OBJS)
	@echo Create the program from the objets...
	@$(CC) $(OFLAGS) $(OBJS) $(CLIB) -o $(NAME)
	@echo Done !

$(OBJD)/%.o : %.c | $(OBJD)
	@echo Create the objets from the source code: $@...
	@$(CC) $(CFLAGS) -I $(INCD) -o $@ -c $^

$(OBJD) :
	@mkdir -p $(OBJD)

clean:
	@echo Clean the objets...
	@$(RM) $(OBJD)

fclean: clean
	@echo Clean the program...
	@$(RM) $(NAME)

re:	fclean all


test: all
	clear
	./test.sh

norm:
	clear
	@(norminette $(INCS) $(SRCS) | grep -v  OK\!) || true

db: all
	${DB} $(NAME)
