/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:21:26 by itishche          #+#    #+#             */
/*   Updated: 2019/03/27 15:21:29 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_fractol.h"

void check_mandelbrot(t_mlx_ptr *mlx)
{
	if (mlx->number_fract == 1)
		original_madelbrot(mlx);
	else if (mlx->number_fract == 4)
		madelbrot2(mlx);
	else if (mlx->number_fract == 5)
		madelbrot3(mlx);
	else if (mlx->number_fract == 6)
		flyingsquirrel(mlx);
	else if (mlx->number_fract == 7)
		mandelbar(mlx);
	else if (mlx->number_fract == 3)
		print_burning_ship(mlx);
}

void	print_mandelbrot(t_mlx_ptr *mlx)
{
	mlx->x = 0;
	while (mlx->x < HEIGHT)
	{
		mlx->y = 0;
		while (mlx->y < WIDTH)
		{
			mlx->c.re = mlx->x / mlx->zoom + mlx->start_x;
			mlx->c.im = mlx->y / mlx->zoom + mlx->start_y;
			ft_bzero(&mlx->z, sizeof(t_complex));
			mlx->iter = 0;
			check_mandelbrot(mlx);
			put_color(mlx);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
}

void		init_mandelbrot(t_mlx_ptr *mlx)
{
	mlx->start_y = -2.23;
	mlx->start_x = -3.03;
	mlx->zoom = 250;
	mlx->max_iter = 100;
}
