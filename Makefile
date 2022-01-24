HDR			= minitalk.h
HDR_B		= minitalk_bonus.h
NAME_SRV	= server
NAME_CL		= client
SRC_SRV		= server.c
OBJ_SRV		= $(SRC_SRV:.c=.o)
SRC_CL		= client.c
OBJ_CL		= $(SRC_CL:.c=.o)
SRC_SRV_B	= server_bonus.c
OBJ_SRV_B	= $(SRC_SRV_B:.c=.o)
SRC_CL_B	= client_bonus.c
OBJ_CL_B	= $(SRC_CL_B:.c=.o)
LIB_SRC		= ./libft/
LIB_NAME	= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all: server client

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -I. -I$(LIB_SRC) -c $< -o $@

$(LIB_SRC)$(LIB_NAME) : libft ;

libft :
	make -C $(LIB_SRC)

server: $(OBJ_SRV) $(LIB_SRC)$(LIB_NAME) $(HDR)
	$(CC) $(CFLAGS) $(OBJ_SRV) $(LIB_SRC)$(LIB_NAME) -o $(NAME_SRV)

client: $(OBJ_CL) $(LIB_SRC)$(LIB_NAME) $(HDR)
	$(CC) $(CFLAGS) $(OBJ_CL) $(LIB_SRC)$(LIB_NAME) -o $(NAME_CL)

bonus: server_b client_b

server_b: $(OBJ_SRV_B) $(LIB_SRC)$(LIB_NAME) $(HDR_B)
	$(CC) $(CFLAGS) $(OBJ_SRV_B) $(LIB_SRC)$(LIB_NAME) -o $(NAME_SRV)

client_b: $(OBJ_CL_B) $(LIB_SRC)$(LIB_NAME) $(HDR_B)
	$(CC) $(CFLAGS) $(OBJ_CL_B) $(LIB_SRC)$(LIB_NAME) -o $(NAME_CL)

clean:
	rm -f $(OBJ_SRV) $(OBJ_CL) $(OBJ_SRV_B) $(OBJ_CL_B)
	make clean -C $(LIB_SRC)

fclean: clean
	rm -f $(NAME_SRV) $(NAME_CL)
	make fclean -C $(LIB_SRC)

re: fclean all

.PHONY : all libft clean fclean re
