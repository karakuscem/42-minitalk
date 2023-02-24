# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckarakus <ckarakus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 22:10:21 by ckarakus          #+#    #+#              #
#    Updated: 2023/02/24 22:17:31 by ckarakus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER			=	server
SERVER_SRC		=	server.c

CLIENT			=	client
CLIENT_SRC		=	client.c 

UTILS_SRC		=	utils.c 

BONUS_SERVER		=	server_bonus
BONUS_CLIENT		=	client_bonus
BONUS_SERVER_SRC	=	server_bonus.c
BONUS_CLIENT_SRC	=	client_bonus.c
BONUS_UTILS_SRC		=	utils_bonus.c

CC			=	@gcc
RM 			=	@rm -f
FLAGS			= 	-Wall -Werror -Wextra

all : $(SERVER) $(CLIENT)

bonus : $(BONUS_SERVER) $(BONUS_CLIENT)

$(SERVER) : $(SERVER_OBJ) $(UTILS_OBJ)
	$(CC) $(FLAGS) $(SERVER_SRC) $(UTILS_SRC) -o $(SERVER)

$(CLIENT) : $(CLIENT_OBJ) $(UTILS_OBJ)
	$(CC) $(FLAGS) $(CLIENT_SRC) $(UTILS_SRC) -o $(CLIENT)

$(BONUS_SERVER) : $(BONUS_SERVER_OBJ) $(BONUS_UTILS_OBJ)
	$(CC) $(FLAGS) $(BONUS_SERVER_SRC) $(BONUS_UTILS_SRC) -o $(BONUS_SERVER)

$(BONUS_CLIENT) : $(BONUS_CLIENT_OBJ) $(BONUS_UTILS_OBJ)
	$(CC) $(FLAGS) $(BONUS_CLIENT_SRC) $(BONUS_UTILS_SRC) -o $(BONUS_CLIENT)

fclean : clean

clean :
	@rm -rf server client server_bonus client_bonus

re : fclean all

.PHONY: all fclean re bonus