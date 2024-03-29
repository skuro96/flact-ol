#include "fractol.h"

void	draw_pixel(t_info *info, int x, int y, int color)
{
	char	*dst;

	dst = info->img.data + (y * info->img.size_l + x * (info->img.bpp / 8));
	*(unsigned int *)dst = color;
}

int	mandelbrot_n(double x, double y, int n)
{
	double	a;
	double	b;
	double	tmp_a;
	int		k;

	a = 0;
	b = 0;
	k = 0;
	while (k < n)
	{
		tmp_a = a * a - b * b + x;
		b = 2 * a * b + y;
		a = tmp_a;
		if (a * a + b * b > 4.0)
			return (k);
		k++;
	}
	return (-1);
}

int	iterate_n(t_vars vars)
{
	double	w;
	int		n;

	w = vars.ex - vars.sx;
	n = 0;
	while (1.0 / pow(2, n) > w)
		n++;
	return (n * 10 + 50);
}

void	draw_mandelbrot(t_info *info)
{
	int		i;
	int		j;
	double	x;
	double	y;
	int		n;

	i = 0;
	while (i < HEIGHT)
	{
		y = info->vars.sy + (info->vars.ey - info->vars.sy) * i / HEIGHT;
		j = 0;
		while (j < WIDTH)
		{
			x = info->vars.sx + (info->vars.ex - info->vars.sx) * j / WIDTH;
			n = mandelbrot_n(x, y, iterate_n(info->vars));
			if (n == -1)
				draw_pixel(info, j, i, 0x000000);
			else
				draw_pixel(info, j, i, n * pow(16, 3) + 0x4000a0);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}
