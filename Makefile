##
## Makefile<PSU_2016_nmobjdump> for Makefile in /home/zeng_d
##
## Made by David Zeng
## Login   <zeng_d@epitech.net>
##
## Started on  Sat Feb 18 16:46:01 2017 David Zeng
## Last update Sat Feb 18 16:46:01 2017 David Zeng
##

NAME_SERVER	:= zappy_server
NAME_AI		:= zappy_ai
NAME_GRAPHIC	:= zappy_graphic

DIR_SERVER	:= server/
DIR_AI		:= clients/ia/
DIR_GRAPHIC	:= clients/graphic/

MV		:= mv
RM		:= rm -f

all: $(NAME_SERVER) $(NAME_AI) $(NAME_GRAPHIC)

$(NAME_SERVER):
	$(MAKE) -C $(DIR_SERVER)
	$(MV) $(DIR_SERVER)$(NAME_SERVER) ./

$(NAME_AI):
	$(MAKE) -C $(DIR_AI)
	$(MV) $(DIR_AI)$(NAME_AI) ./

$(NAME_GRAPHIC):
	$(MAKE) -C $(DIR_GRAPHIC)
	$(MV) $(DIR_GRAPHIC)$(NAME_GRAPHIC) ./

clean:
	$(MAKE) -C $(DIR_SERVER) clean
	$(MAKE) -C $(DIR_AI) clean
	$(MAKE) -C $(DIR_GRAPHIC) clean

fclean:
	$(MAKE) -C $(DIR_SERVER) fclean
	$(MAKE) -C $(DIR_AI) fclean
	$(MAKE) -C $(DIR_GRAPHIC) fclean
	$(RM) $(NAME_SERVER)
	$(RM) $(NAME_AI)
	$(RM) $(NAME_GRAPHIC)

re: fclean all

.PHONY: all clean fclean re
