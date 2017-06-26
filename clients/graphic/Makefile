NAME		=	zappy_graphic
DIR_SRC		=	src
DIR_INC		=	inc

CC		=	g++
CFLAGS		=	-W -Wall -Werror -Wextra -I./$(DIR_INC)
LDFLAGS		=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio #-lsfml-network

ECHO		=	/bin/echo -e
DEFAULT		=	"\e[0m"
GREY		=	"\e[1m\e[38;5;247m"
RED		=	"\e[1m\e[38;5;196m"
YELLOW		=	"\e[1m\e[38;5;227m"
BLUE		=	"\e[1m\e[38;5;38m"
GREEN		=	"\e[1m\e[38;5;118m"
COMPILED	=	$(BLUE)"[COMPILED]\t"
LINKED		=	$(GREEN)"[LINKED]\t"
DELETED		=	$(RED)"[DELETED]\t"
ARROW		=	$(BLUE)"\t=>\t"

SRC		=	$(DIR_SRC)/main.cpp \
			$(DIR_SRC)/Graph.cpp \
			$(DIR_SRC)/Player.cpp \
			$(DIR_SRC)/TileMap.cpp

OBJ		=	$(SRC:.cpp=.o)

# ---------- Rules ----------

all:			$(NAME)

$(NAME):		$(OBJ)
			@$(CC) -o $@ $^ $(LDFLAGS)
			@$(ECHO) $(LINKED) $(YELLOW) $(NAME) $(DEFAULT)

%.o:			%.cpp
			@$(CC) -c $< -o $@ $(CFLAGS)
			@$(ECHO) $(COMPILED) $(GREY) $< $(ARROW) $(GREY) $@ $(DEFAULT)

clean:
			@rm -f $(OBJ)
			@$(ECHO) $(DELETED) $(GREY) $(OBJ) $(DEFAULT)

fclean:			clean
			@rm -f $(NAME)
			@$(ECHO) $(DELETED) $(YELLOW) $(NAME) $(DEFAULT)

re:			fclean all

.PHONY:			all clean fclean re
