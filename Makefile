# **************************************************************************** #
#                                                                              #
#                                                        ::::::::              #
#    Makefile                                          :+:    :+:              #
#                                                     +:+                      #
#    By: sreerink <sreerink@student.codam.nl>        +#+                       #
#                                                   +#+                        #
#    Created: 2024/11/19 13:45:48 by sreerink      #+#    #+#                  #
#    Updated: 2025/01/23 17:14:33 by sreerink      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME= 		cub3D

RM= 		rm -rf

FLAGS= 		# -Wall -Werror -Wextra

SRC_DIR=	src

OBJ_DIR=	obj

SRCS=		$(addprefix $(SRC_DIR)/, main.c init_cube.c cube_hook.c \
			key_input.c exit_cube.c)	

OBJ=		$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

MLX=		./MLX42

MLX_LIB=	$(MLX)/build/libmlx42.a

MLX_FLAGS=	-ldl -lglfw -pthread -lm

LIBFT=		./Libft/libft.a

ANIM=		./MLX42_animation/MLX42_animation.a

HEADERS=	-I ./Libft -I ./MLX42_animation/include -I $(MLX)/include


all:	SUBMODULES_INIT $(NAME)

$(MLX_LIB):
	@if [ ! -f $(MLX_LIB) ]; then \
		cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4; \
	fi

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ./Libft

$(ANIM):
	$(MAKE) -C ./MLX42_animation

$(NAME): 	$(LIBFT) $(ANIM) $(MLX_LIB) $(OBJ)
	$(CC) $(OBJ) $(ANIM) $(MLX_LIB) -L./Libft -L./MLX42_animation -lft $(MLX_FLAGS) -o $(NAME)

SUBMODULES_INIT:
	@git submodule update --init --recursive

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)
	$(RM) $(MLX)/build
	$(MAKE) -C ./Libft clean
	$(MAKE) -C ./MLX42_animation clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C ./Libft fclean
	$(MAKE) -C ./MLX42_animation fclean

re:		fclean all

.PHONY:	all clean fclean re
