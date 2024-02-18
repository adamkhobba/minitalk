# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adamkhobba <marvin@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 17:16:07 by adamkhobba        #+#    #+#              #
#    Updated: 2024/02/14 17:16:09 by adamkhobba       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#************************************** var ******************

NAME = Minitalk.a

SERVER = server

CLIENT = client

CFLAGS = -Wall -Wextra -Werror

SRC_SERVER = src/server/server.c

SRC_CLIENT = src/client/client.c

LIBTF = cd lib/libft && make

PRINTF = cd lib/Printf && make

LIB_LIBTF = lib/libft/libft.a

LIB_PRINTF = lib/Printf/ft_printf.a
 
OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ = $(OBJ_CLIENT)\
			$(OBJ_SERVER)

#****************************commands************************

all : start server client
start :
	$(LIBTF)
	$(PRINTF)

server : $(OBJ_SERVER)
	@cc $(FLAGS) $(SRC_SERVER) $(LIB_LIBTF) $(LIB_PRINTF) -o $(SERVER) 
	@echo "\e[1;32m Server ready 🗄️\e[0m" 

client : $(OBJ_CLIENT)
	@cc $(FLAGS) $(SRC_CLIENT) $(LIB_LIBTF) $(LIB_PRINT) -o $(CLIENT)
	@echo "\e[1;31m Client ready ⌨️ \e[0m" 

clean :
	rm -f $(OBJ)
	cd lib/libft && make clean
	cd lib/Printf && make clean
 
fclean : clean
	rm -f $(SERVER) $(CLIENT)
	cd lib/libft && make fclean
	cd lib/Printf && make fclean

re : fclean all
