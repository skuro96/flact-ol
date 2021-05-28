#include "fractol.h"

void	draw_pixel(t_info *info, int x, int y, int color)
{
	char	*dst;

	dst = info->img.data + (y * info->img.size_l + x * (info->img.bpp / 8));
	*(unsigned int *)dst = color;
}

bool	is_mandelbrot(double x, double y)
{
	double	a;
	double	b;
	double	tmp_a;
	int		i;

	a = 0;
	b = 0;
	i = 0;
	while (i < 20)
	{
		tmp_a = a * a - b * b + x;
		b = 2 * a * b + y;
		a = tmp_a;
		if (a * a + b * b > 4.0)
			return (false);
		i++;
	}
	return (true);
}

int	mandelbrot_n(double x, double y)
{
	double	a;
	double	b;
	double	tmp_a;
	int		k;

	a = 0;
	b = 0;
	k = 0;
	while (k < 50)
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
			n = mandelbrot_n(x, y);
			if (n == -1)
				draw_pixel(info, j, i, 0x000000);
			else
				draw_pixel(info, j, i, n * pow(16, 3) + 0x4000a0);
			j++;
		}
		i++;
	}
}
