CC	= g++

RM	= rm -f

NAME	=	zoo

OBJ	=	${SRC:.cpp=.o}

SRC	=	src/main.cpp \
		src/animal.cpp \
		src/habitat.cpp \
		src/prix.cpp \
		src/zoo.cpp \
		src/globalmenu.cpp \
		src/menuanimal.cpp \
		src/menuhabitat.cpp \
		src/menunourriture.cpp \

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC)  -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) zoo

re:	fclean all