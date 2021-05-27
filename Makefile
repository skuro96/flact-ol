CC		= gcc
INCLUDE = -I./minilibx -I./include

CFLAGS	= -Wall -Wextra -Werror $(INCLUDE)
MLXFLAGS = -L./minilibx -lmlx -framework OpenGL -framework AppKit

all:
	$(CC) $(CFLAGS) $(MLXFLAGS) src/*.c
	./a.out
