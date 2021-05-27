#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h> // open
# include <unistd.h> // close, read, write
# include <stdio.h> // printf, perror, strerror
# include <stdlib.h> // malloc, free, exit
# include <math.h>
# include <mlx.h>
# include <stdbool.h> // boolean

# define HEIGHT 600
# define WIDTH 800

typedef struct s_img
{
	void	*img;
	char	*data;
	int		bpp;
	int		size_l;
	int		endian;
}t_img;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	t_img	img;
}t_info;

void	draw_mandelbrot(t_info *info);

#endif