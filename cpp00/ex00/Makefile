NAME = megaphone

SRC = megaphone.cpp

OBJS = ${SRCS:.c=.o}

CXX = c++98

CXXFLAGS = -Wall -Werror -Wextra

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re