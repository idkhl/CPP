NAME = MutantStack

SRCS = main.cpp 

OBJS = ${SRCS:.cpp=.o}

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -I ./includes

RM = rm -f

.cpp.o:
	c++ $(CXXFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)


%.o : %.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o ${<:.cpp=.o}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re