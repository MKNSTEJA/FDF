# Project Name
NAME = fdf

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Library Paths and Files
FT_PRINTF = ./ft_printf/libftprintf.a
LIBFT = ./ft_printf/libft/libft.a
MLX = ./MLX42/build/libmlx42.a

ifeq ($(shell uname), Darwin)
    MLX_FLAGS = -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
else ifeq ($(shell uname), Linux)
    MLX_FLAGS = -L./MLX42/build -lglfw -ldl -pthread -lm
endif

# Directories
SRCS_DIR = .
INCLUDES = ./ft_printf ./MLX42/include/MLX42 ./ft_printf/libft
OBJ_DIR = ./obj

# Source Files
SRCS = main.c fdf.c get_next_line.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))


# Default rule
all: mlx_lib ft_lib printf_lib $(NAME)

# Compile the main project
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ $(FT_PRINTF) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $@

# Object file compilation
$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

# Create the object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Build the MLX42 library
mlx_lib:
	cd MLX42 && cmake -B build && make -C build -j4

# Build the ft_printf library
printf_lib:
	$(MAKE) -C ft_printf

# Build the libft library (as part of ft_printf)
ft_lib:
	$(MAKE) -C ft_printf/libft

# Clean object files and intermediate builds
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C ft_printf clean
	$(MAKE) -C ft_printf/libft clean
	cd MLX42 && rm -rf build

# Full clean
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C ft_printf/libft fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re mlx_lib ft_lib printf_lib
