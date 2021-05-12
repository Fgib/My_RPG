##
## EPITECH PROJECT, 2021
## B-PSU-101-LYN-1-1-minishell1-florian.gibault
## File description:
## Makefile
##

SRC		=	$(shell find . -type f -name "*.c")

OBJ 	= 	$(SRC:.c=.o)

CFLAGS	=	$(EFLAGS)

EFLAGS	=	-Werror -Wall -Wextra -Wpedantic

NAME 	= 	libmy.a

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

all:	
	@ make start -s
	@ ar rc $(NAME) $(OBJ)
	@ mkdir -p ../../inc
	@ cp libmy.h ../../inc
	@ cp $(NAME) ../$(NAME)
	@ make clean

	@ printf "$(YELLOW)===== LIBRARIES COMPILATION =====\n$(WHITE)" --no-print-directory
	@ printf "$(PURPLE)Starting My library compilation...\n$(WHITE)"
	@ printf "$(PURPLE)| --> Compiling .c to Object file...\n$(WHITE)"
	@ make start -s
	@ printf "$(PURPLE)| --> Compiling Object files into .a...\n$(WHITE)"
	@ ar rc $(NAME) $(OBJ)
	@ printf "$(PURPLE)| --> Copying library to lib folder...\n$(WHITE)"
	@ cp $(NAME) ../$(NAME)
	@ printf "$(PURPLE)| --> Copying Header file into include directory...\n$(WHITE)"
	@ cp libmy.h ../../inc/libmy.h
	@ printf "$(GREEN)[OK]$(PURPLE) Lib_my successfully compiled !\n\n$(WHITE)"
	@ make clean

start:	$(OBJ)

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f ../$(NAME)
	@ rm -f $(NAME)

re: fclean all