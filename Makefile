# Fractal Program Makefile

NAME = fractol
CC = cc
FLAGS = -Wall -Werror -Wextra -g -O3 -march=native -flto

# Paths
MLX_PATH = /usr/local/lib
LIBFT_PATH = ./Libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
INCLUDES = -I. -I$(LIBFT_PATH) -I/usr/local/include

# Libraries
LIBS = -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -lX11 -lXext -lm -lz

# Source files
SRCS = main.c complex.c hooks.c mandelbrot.c julia.c burningship.c  input_parse.c windowsettings.c fractol.c fractolutls.c

# Object files
OBJS = $(SRCS:.c=.o)

# Rules
all: $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
