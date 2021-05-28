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

typedef struct s_vars
{
	double	sx;
	double	sy;
	double	ex;
	double	ey;
	double	zoom;
}t_vars;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_vars	vars;
}t_info;

int		key_hook(int keycode, t_info *info);
int		mouse_hook(int keycode, int x, int y, t_info *info);

void	draw_mandelbrot(t_info *info);

#endif