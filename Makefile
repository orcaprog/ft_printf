NAME   = libftprintf.a

SRCS   = ft_printf.c \
         ft_putstr.c \
		 ft_putnbr.c \
		 ft_putchar.c \
		 ft_hexa.c  \
		 ft_ptrhex.c  \
		 ft_unsign.c

OBJS	= ${SRCS:.c=.o}

RM		= rm -rf

CC		= cc

AR		= ar rc

CFLAGS = -Wall -Werror -Wextra

all	:	$(NAME)


$(NAME)	:	$(OBJS)
		$(AR) $(NAME) $(OBJS)

clean	:
		$(RM) ${OBJS}


fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all