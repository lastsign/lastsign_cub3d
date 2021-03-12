NAME = cub3D

LIBFT_HEADER = srcs/libft

LIB_SRCS = ft_substr.c \
		ft_strlen.c \
		ft_bzero.c \
		ft_strjoin.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strtrim.c \
		ft_strchr.c \
		ft_split.c \
		ft_strrchr.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_strmapi.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_isalnum.c \
		ft_calloc.c \
		ft_strdup.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c ft_lstsize.c
LIB_OBJ = $(addprefix $(LIBFT_HEADER)/,$(LIB_SRCS:.c=.o))

SRCS = srcs/add_sprite.c\
		srcs/ft_free.c \
		srcs/ft_init_sprites.c \
		srcs/main.c \
		srcs/move_rotate.c \
		srcs/move_rotate_util.c \
		srcs/parse_map.c \
		srcs/parse_resol_color.c \
		srcs/parser.c \
		srcs/parser_text_elem.c \
		srcs/parser_utils.c \
		srcs/raycaster.c \
		srcs/raycaster_utils.c \
		srcs/try_make_screen.c \
		srcs/utils.c \
		srcs/libft/get_next_line_utils.c \
		srcs/libft/get_next_line.c
OBJ = $(SRCS:.c=.o)

MLX = libmlx.dylib
LIBFT = srcs/libft/libft.a

INCLUDE = includes

LIBMLX = mlx

HEADES = srcs/libft/libft.h includes/cub3d.h mlx/mlx.h

FLAG = -Wall -Wextra -Werror -I $(LIBFT_HEADER) -I $(INCLUDE) -I $(LIBMLX)

all: $(NAME)

srcs/%.o:srcs/%.c $(HEADES)
	@gcc $(FLAG) -o $@ -c $<

$(LIBFT_HEADER)/%.o:$(LIBFT_HEADER)/%.c $(LIBFT_HEADER)/libft.h
	@$(MAKE) -C $(LIBFT_HEADER)

$(NAME): $(OBJ) $(LIB_OBJ)
	@$(MAKE) -C ./mlx
	@$(MAKE) -C $(LIBFT_HEADER)
	@mv ./mlx/$(MLX) . && rm -f ./mlx/$(MLX)
	@gcc $(FLAG) $(OBJ) $(LIBFT) -L. -lmlx -lm -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@$(MAKE) -C ./mlx clean
	@$(MAKE) -C ./srcs/libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(MLX)
	@/bin/rm -f $(LIBFT)
	@/bin/rm -f $(NAME)
	@/bin/rm -f screenshot.bmp

re: fclean all

.PHONY: all clean fclean re
