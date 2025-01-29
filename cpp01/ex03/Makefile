NAME = brain

SRCS = main.cpp Weapon.hpp Weapon.cpp HumanA.hpp HumanA.cpp HumanB.hpp HumanB.cpp

OBJS = ${SRCS:.cpp=.o}

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -I ./includes

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