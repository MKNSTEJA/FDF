# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = .
OBJ_DIR = obj

# Source and Object Files
SRCS = main.c fdf.c store_info.c get_next_line.c get_next_line_utils.c window.c draw.c algo.c
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Libraries
LIBFT = ./ft_printf/libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
MLX_LIB = ./MLX42/build/libmlx42.a

# MLX Flags
ifeq ($(shell uname), Darwin)
	MLX_FLAGS = -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
else
	MLX_FLAGS = -L./MLX42/build -lglfw -ldl -pthread -lm
endif

# Target
NAME = fdf

# Compilation Rules
all: libft ft_printf mlx $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build Libraries
libft:
	@$(MAKE) -C ft_printf/libft

ft_printf:
	@$(MAKE) -C ft_printf

mlx:
	@cd MLX42 && cmake -B build && make -C build -j4

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C ft_printf/libft clean
	@$(MAKE) -C ft_printf clean
	@cd MLX42 && rm -rf build

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C ft_printf/libft fclean
	@$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re libft ft_printf mlx
