#include "fractol.h"

void	move(t_info *info, int keycode, double len)
{
	if (keycode == 123)
	{
		info->vars.sx -= len;
		info->vars.ex -= len;
	}
	else if (keycode == 124)
	{
		info->vars.sx += len;
		info->vars.ex += len;
	}
	else if (keycode == 125)
	{
		info->vars.sy += len;
		info->vars.ey += len;
	}
	else if (keycode == 126)
	{
		info->vars.sy -= len;
		info->vars.ey -= len;
	}
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode == 53)
	{
		mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	else if (123 <= keycode && keycode <= 126)
		move(info, keycode, 0.05);
	else
		printf("keycode = %d\n", keycode);
	return (1);
}

void	zoom(t_info *info, double zoom)
{
	t_vars	*v;
	double	center_x;
	double	center_y;
	double	dx;
	double	dy;

	v = &info->vars;
	center_x = (v->ex + v->sx) / 2;
	center_y = (v->ey + v->sy) / 2;
	dx = (v->ex - v->sx) * zoom;
	dy = (v->ey - v->sy) * zoom;
	v->sx = center_x - dx / 2;
	v->sy = center_y - dy / 2;
	v->ex = center_x + dx / 2;
	v->ey = center_y + dy / 2;
}

int	mouse_hook(int keycode, int x, int y, t_info *info)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		zoom(info, 1.1);
	else if (keycode == 5)
		zoom(info, 0.9);
	return (0);
}
