NAME		= libasm.a

SRC			=	ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_strdup.s \
				ft_write.s \
				ft_read.s \

OBJ			= $(SRC:.s=.o)

AC			= nasm
AFLAGS		= -f macho64
FLAGS 		= -c -Wall -Werror -Wextra
RM			= rm -f

%.o: %.s
			$(AC) $(AFLAGS) $^

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

test:		$(NAME)
			gcc main.c libasm.a

.PHONY:		all clean fclean re
