NAME = fixed

SRCS = main.cpp  Fixed.cpp

OBJS = ${SRCS:.cpp=.o}

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -I ./includes

RM = rm -f

.cpp.o:
	cc $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re