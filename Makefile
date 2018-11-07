##
## Created by Victor Lucas
##

SRC	=	ncurse/BoxNcurse.cpp		\
		ncurse/CPU.cpp			\
		ncurse/DateTime.cpp		\
		ncurse/hostname_username.cpp	\
		ncurse/Kernel.cpp		\
		ncurse/Network.cpp		\
		ncurse/OperatingSystem.cpp	\
		ncurse/Ram.cpp  		\
		sfml/Box.cpp			\
		sfml/GetBoxes.cpp		\
		launch.cpp			\
		main.cpp

NAME	=	monitor

CFLAGS	+=	-W -Wall -Wextra -Werror
CFLAGS	+=	-LSFML/lib -lsfml-window -lsfml-graphics
CFLAGS	+=	-lsfml-system -ISFML/include -lncurses -std=c++11

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME)  $(SRC) $(CFLAGS)


fclean:
		rm -f $(NAME)

clean:		fclean

re:		clean fclean all

.PHONY:		all clean fclean re
