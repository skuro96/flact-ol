#include "fractol.h"

void	draw_pixel(t_info *info, int x, int y, int color)
{
    char    *dst;

    dst = info->img.data + (y * info->img.size_l + x * (info->img.bpp / 8));
    *(unsigned int*)dst = color;
}

bool is_mandelbrot(double x, double y)
{
	double a, b, tmp_a;
	int i;

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

void draw_mandelbrot(t_info *info)
{
	int i, j;
	double x, y;

	for (i = 0; i < HEIGHT; i++)
	{
		y = i * 3.0 / HEIGHT - 1.5;
		for (j = 0; j < WIDTH; j++)
		{
			x = j * 4.0 / WIDTH - 2.5;
			if (is_mandelbrot(x, y))
				draw_pixel(info, j, i, 0xffffff);
			else
				draw_pixel(info, j, i, 0x000000);
		}
	}
}
