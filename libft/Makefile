DIR_OBJ	=	./objs

HEADER	=	libft.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -g

NAME	=	libft.a

AR		=	ar rc


SRCS		= 	ft_isalpha.c	\
				ft_isdigit.c	\
				ft_isalnum.c	\
				ft_isascii.c	\
				ft_isprint.c	\
				ft_strlen.c		\
				ft_memset.c		\
				ft_bzero.c		\
				ft_memcpy.c		\
				ft_memmove.c	\
				ft_strlcpy.c	\
				ft_strlcat.c	\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_strncmp.c	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_strnstr.c	\
				ft_atoi.c		\
				ft_calloc.c		\
				ft_strdup.c		\
				ft_substr.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_split.c		\
				ft_itoa.c		\
				ft_strmapi.c	\
				ft_striteri.c	\
				ft_putchar_fd.c \
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c

SRCS_BONUS	=	ft_lstnew_bonus.c		\
				ft_lstsize_bonus.c		\
				ft_lstadd_front_bonus.c	\
				ft_lstlast_bonus.c		\
				ft_lstadd_back_bonus.c

OBJS		=	${addprefix ${DIR_OBJ}/, ${notdir ${SRCS:.c=.o}}}

OBJS_BONUS	=	${addprefix ${DIR_OBJ}/, ${notdir ${SRCS_BONUS:.c=.o}}}

RM		=	rm -f


all:		${NAME}

${DIR_OBJ}/%.o : %.c | ${DIR_OBJ}
	${CC} ${CFLAGS} -o $@ -c $^

${NAME}:	${OBJS}
	${AR} ${NAME} ${OBJS} 
	ranlib ${NAME}

clean:
	${RM} ${OBJS}
	${RM} ${OBJS_BONUS}

fclean:		clean
	${RM} ${NAME}

re:			fclean	all

${DIR_OBJ} :
	@mkdir -p ${DIR_OBJ}

bonus:		${OBJS} ${OBJS_BONUS}
	${AR} ${NAME} ${OBJS} ${OBJS_BONUS}
	ranlib ${NAME}

log:
	git log --graph --oneline

norm:
	norminette ${SRCS}
	norminette -RCheckDefine ${HEADER}

.PHONY: all clean fclean re bonus so
