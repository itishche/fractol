/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:23:04 by itishche          #+#    #+#             */
/*   Updated: 2019/03/28 11:23:05 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_fractol.h"

int			mouse_julia(int x, int y, t_mlx_ptr *mlx)
{
	if (x > 0 && y > 0 && x < HEIGHT && y < WIDTH)
	{
		if (mlx->number_fract == 2 && mlx->mouse_on_off == 1)
		{
			mlx->c.re = x * 2;
			mlx->c.im = y * 2 - 800;
			print_julia(mlx);
		}
	}
	return (0);
}

void	julia_calculation(t_mlx_ptr *mlx)
{
	double	x_new;

	while (mlx->z.re * mlx->z.re + mlx->z.im * mlx->z.im < 4 
				&& mlx->iter < mlx->max_iter)
	{
		x_new = mlx->z.re * mlx->z.re - mlx->z.im * mlx->z.im - 0.8 + mlx->c.re / WIDTH;
		mlx->z.im = 2 * mlx->z.re * mlx->z.im + mlx->c.im / WIDTH;
		mlx->z.re = x_new;
		mlx->iter++;
	}
}

void	print_julia(t_mlx_ptr *mlx)
{
	mlx->x = 0;
	while (mlx->x < HEIGHT)
	{
		mlx->y = 0;
		while (mlx->y < WIDTH)
		{
			mlx->z.re = mlx->x / mlx->zoom + mlx->start_x;
			mlx->z.im = mlx->y / mlx->zoom + mlx->start_y;
			mlx->iter = 0;
			julia_calculation(mlx);
			put_color(mlx);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
}

void		init_julia(t_mlx_ptr *mlx)
{
	mlx->mouse_on_off = 0;
	mlx->start_y = -2.23;
	mlx->start_x = -2.13;
	mlx->zoom = 250;
	mlx->max_iter = 50;
	mlx->c.re = 0.285;
	mlx->c.im = 0.01;
}
