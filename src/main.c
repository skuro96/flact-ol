#include "fractol.h"

void	init(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "flact-ol");
	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->img.data = mlx_get_data_addr(\
		info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);
	info->vars.sx = -2;
	info->vars.ex = 2;
	info->vars.sy = -1.5;
	info->vars.ey = 1.5;
}

int	main_loop(t_info *info)
{
	draw_mandelbrot(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_info	info;

	init(&info);
	mlx_hook(info.win, 2, 1L << 0, &key_hook, &info);
	mlx_hook(info.win, 4, 1L << 0, &mouse_hook, &info);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_loop(info.mlx);
}
