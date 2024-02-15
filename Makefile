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

CFLAGS = -Wall -Wextra -Werror 

SRC_SERVER =  src/server/server.c

SRC_CLIENT =  src/client/client.c

LIBTF = cd lib/libft  && make

PRINTF = cd lib/Printf && make

LIB_LIBTF = lib/libft/libft.a

LIB_PRINTF = lib/Printf/ft_printf.a
 
OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ = $(OBJ_CLIENT)\
			$(OBJ_SERVER)

SERVER = server

CLIENT = client 

#*************************************** colors *************

#****************************commands************************

all : start server client

start : 
	$(LIBTF)
	$(PRINTF)

server : $(OBJ_SERVER)
	cc $(FLAGS) $(OBJ_SERVER) $(LIB_LIBTF) $(LIB_PRINTF) -o $(SERVER) 

client : $(OBJ_CLIENT)
	cc $(FLAGS) $(OBJ_CLIENT) $(LIB_LIBTF) $(LIB_PRINT) -o $(CLIENT)  

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $@

clean : 
	rm -f $(OBJ)
	cd lib/libft && make clean
	cd lib/Printf && make clean
 
fclean : clean
	rm -f $(NAME)
	cd lib/libft && make fclean
	cd lib/Printf && make fclean

re : fclean all
