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

int main_loop(t_info *info)
{
	draw_mandelbrot(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	return (0);
}

void	window_init(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "flact-ol");
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