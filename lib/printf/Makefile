##
## EPITECH PROJECT, 2020
## C Pool Day 10
## File description:
## Makefile
##

SRC		=	$(shell find . -type f -name "*.c")

OBJ 	= 	$(SRC:.c=.o)

NAME 	= 	libprintf.a

#COLORS
WHITE	=	\e[0m
RED		=	\e[1;31m
GREEN	=	\e[1;32m
YELLOW	=	\e[1;33m
BLUE	=	\e[1;34m
#DEFAULT   = \033[0m
#HIGHLIGHT = \033[1m
#UNDERLINE = \033[4m
#BLINK     = \033[5m
#BLACK     = \033[30m
PURPLE    = \033[35m
#CYAN      = \033[36m

all: 	$(NAME)

$(NAME): 	
	@ printf "$(PURPLE)Starting MyPrintf Library compilation...\n$(WHITE)"
	@ printf "$(PURPLE)| --> Compiling .c to Object file...\n$(WHITE)"
	@ make start -s
	@ printf "$(PURPLE)| --> Compiling Object files into .a...\n$(WHITE)"
	@ ar rc $(NAME) $(OBJ)
	@ printf "$(PURPLE)| --> Copying library to lib folder...\n$(WHITE)"
	@ cp $(NAME) ../$(NAME)
	@ printf "$(GREEN)[OK]$(PURPLE) MyPrintf lib successfully compiled !\n\n$(WHITE)"
	@ make clean

start:	$(OBJ)

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ printf "$(PURPLE)Starting printf library Cleanup...\n$(WHITE)"
	@ printf "$(PURPLE)| --> Deleting .a file...\n$(WHITE)"
	@ rm -f ../$(NAME) $(NAME)
	@ printf "$(GREEN)[OK]$(PURPLE) libprintf successfully cleaned !\n\n$(WHITE)"

re: fclean all