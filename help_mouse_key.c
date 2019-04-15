/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_mouse_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:23:40 by itishche          #+#    #+#             */
/*   Updated: 2019/03/27 15:23:44 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_fractol.h"

void	key_function2(int keycode, t_mlx_ptr *mlx)
{
	mlx->number_fract = keycode == 18 ? 1 : mlx->number_fract;
	mlx->number_fract = keycode == 19 ? 2 : mlx->number_fract;
	mlx->number_fract = keycode == 20 ? 3 : mlx->number_fract;
	mlx->number_fract = keycode == 21 ? 4 : mlx->number_fract;
	mlx->number_fract = keycode == 23 ? 5 : mlx->number_fract;
	mlx->number_fract = keycode == 22 ? 6 : mlx->number_fract;
	mlx->number_fract = keycode == 26 ? 7 : mlx->number_fract;
	if (keycode == 19)
		init_julia(mlx);
	else
		init_mandelbrot(mlx);
}

int		key_function(int keycode, t_mlx_ptr *mlx)
{
	if (keycode == 53)
		return(goaway());
	if (keycode == 46)
	{
		if (mlx->mouse_on_off == 1)
			mlx->mouse_on_off = 0;
		else
			mlx->mouse_on_off = 1;
	}
	if ((keycode >= 18 && keycode <= 23) || keycode == 26)
		key_function2(keycode, mlx);
	if (keycode == 24 || keycode == 27)
		mlx->max_iter += keycode == 27 ? -5 : 5;
	else if (keycode == 126 || keycode == 125)
		mlx->start_y += keycode == 125 ? -20 / mlx->zoom : 20 / mlx->zoom ;
	else if (keycode == 123 || keycode == 124)
		mlx->start_x += keycode == 124 ? -20 / mlx->zoom : 20 / mlx->zoom;
	check_fract(mlx);
	return (0);
}

void		zoooom(int x, int y, t_mlx_ptr *mlx)
{
	if (x > 0 && y > 0 && x < HEIGHT && y < WIDTH)
	{
		mlx->start_x = x / mlx->zoom + mlx->start_x - x / (mlx->zoom * 1.5);
		mlx->start_y = y / mlx->zoom + mlx->start_y - y / (mlx->zoom * 1.5);
		mlx->zoom *= 1.5;
		mlx->max_iter--;
	}
}

void		azoooom(int x, int y, t_mlx_ptr *mlx)
{
	if (x > 0 && y > 0 && x < HEIGHT && y < WIDTH)
	{
		mlx->start_x = x / mlx->zoom + mlx->start_x - x / (mlx->zoom / 1.5);
		mlx->start_y = y / mlx->zoom + mlx->start_y - y / (mlx->zoom / 1.5);
		mlx->zoom /= 1.5;
		mlx->max_iter++;
	}
}

int			mouse_hook(int button, int x, int y, t_mlx_ptr *mlx)
{
	if (button == 4)
	{
		if (mlx->zoom <= 9056636893015158.0)
			zoooom(x, y, mlx);
		check_fract(mlx);
	}
	if (button == 5)
	{
		if (mlx->zoom >= 49.3)
			azoooom(x, y, mlx);
		check_fract(mlx);
	}
	return (0);
}
