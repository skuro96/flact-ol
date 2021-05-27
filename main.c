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

int main_loop(t_info *info)
{
	draw_pixel(info, 100, 100, 0x00ff00);
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