#NAME OF THE PROGRAM ===================================
NAME = fractol

#COMPILER STUFF ========================================
CC = gcc

CFLAGS = -Wall -Werror -Wextra

CFLAGS += -O3 #FAST AF

#LIBFT STUFF ===========================================

LIBDIR = libft

#MLX STUFF =============================================

MLXDIR = mlx_linux

#INCLUDE STUFF =========================================
INC = inc

IFLAGS = -I $(INC)
	
IFLAGS += -I $(LIBDIR)/$(INC)

ifeq ($(UNAME), Linux)
	IFLAGS += -I $(MLXDIR)
else
	IFLAGS += -Imlx
endif

#LINKER STUFF ==========================================
LDFLAGS = -Llibft -lft

ifeq ($(UNAME), Linux)
	LDFLAGS += -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	LDFLAGS += -lmlx -framework OpenGL -framework AppKit
endif

#SOURCE STUFF ==========================================
SRCDIR = srcs

SRCFILES = main.c \
	   complex_numbers.c \
	   mandelbrot.c \
	   utils.c \
	   colors.c \
	   parser.c \
	   hooks.c \
	   init.c \
	   color_utils.c \
	   math_utils.c

SRC = $(addprefix $(SRCDIR)/,$(SRCFILES))

#OBJECT STUFF ==========================================

OBJ = $(SRC:%.c=%.o)

#RULES STUFF ===========================================
%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

sanitize: CFLAGS += -g3
sanitize: LDFLAGS += -fsanitize=address -fsanitize=leak
sanitize: all

clean:
	@make clean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re 
