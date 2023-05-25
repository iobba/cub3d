NAME = cub3d
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = Libft/libft.a
PARSING = check_map.c init_prog.c  insert_data.c check_cub.c check_colours.c door.c horizontally_check.c  vertically_check.c player_coords.c \
	ft_realloc.c check_characters.c utils.c utils2.c check_params.c check_walls.c check_line.c
EXECUTION = get_started.c render_all.c control_moves.c ray_caster.c from_0_90.c from_90_180.c from_180_270.c from_270_360.c handle_doors.c control_keys.c render_mini_map.c init_images.c control_hooks.c draw_walls.c

SRCS = $(addprefix ./parsing/,$(PARSING))\
	$(addprefix ./execution/,$(EXECUTION))\
	$(LIBFT) errors.c get_next_line_utils.c  get_next_line.c cub3d.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT) :
	make -C ./Libft

clean :
	rm -rf $(OBJS)
	make -C ./Libft clean

fclean : clean
	rm -rf $(NAME)
	make -C ./Libft fclean

re : fclean all