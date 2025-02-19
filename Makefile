NAME = libftprintf.a
AR=ar rcs
CFLAGS=-Wall -Werror -Wextra
RM=rm -f

FILES = ft_printf.c ft_putn.c

OBJS=$(FILES:.c=.o)


all: $(NAME)

$(NAME): $(OBJS) 
	$(AR) $@ $?

%.o: %.c
	cc -c $(CFLAGS) $?

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re