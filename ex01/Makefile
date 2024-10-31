SRCS	=	main.cpp Contact.cpp PhoneBook.cpp

OBJS	=	${SRCS:.cpp=.o}

CC		=	c++ -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address

NAME	=	phonebook

RM		=	rm -f

all		:	${NAME}

%.o		:	%.cpp
	@${CC} -c $< -o $@

${NAME}	:	${OBJS}
	@${CC} ${OBJS} -o $@
	@echo "compile done"

clean	:
	@${RM} ${OBJS}
	@echo "clear"

fclean	:	clean
	@${RM} ${NAME}
	@echo "clear all"

re		:	fclean all 

.PHONY	:	all clean fclean re
