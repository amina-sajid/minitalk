# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asajid <asajid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 15:34:30 by asajid            #+#    #+#              #
#    Updated: 2023/06/07 12:07:27 by asajid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

CFLAGS = -Wall -Werror -Wextra
CC = cc

all: $(CLIENT) $(SERVER)

$(CLIENT) : client.c utils.c
		$(CC) $(CFLAGS) client.c utils.c -o $(CLIENT)
$(SERVER) : server.c utils.c
		$(CC) $(CFLAGS) server.c utils.c -o $(SERVER)

clean:
	rm -rf $(CLIENT) $(SERVER)

fclean:
	rm -rf $(CLIENT) $(SERVER)

re: fclean all 
