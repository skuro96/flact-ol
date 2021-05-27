#include "fractol.h"

int win_close(int keycode, t_info *info)
{
	if (keycode == 53)
	{
		mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	return (1);
}

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

int main_loop(t_info *info)
{
	draw_mandelbrot(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	return (0);
}

void	window_init(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "mlx 42");
}

void	img_init(t_info *info)
{
	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->img.data = mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);
}

int main(void)
{
	t_info info;

	window_init(&info);
	img_init(&info);

	mlx_hook(info.win, 2, 1L<<0, &win_close, &info);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_loop(info.mlx);
}