/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:41:35 by itishche          #+#    #+#             */
/*   Updated: 2019/03/28 14:41:37 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_fractol.h"

void	change_color(int keycode, t_mlx_ptr *mlx)
{
	if (keycode == 8)
	{
		if (mlx->color == 0xFFFFFF)
			mlx->color = 0x2A0FFF;
		else if (mlx->color == 0x2A0FFF)
			mlx->color = 0x590e0e;
		else if (mlx->color == 0x590e0e)
			mlx->color = 0x0b192a;
		else
			mlx->color = 0xFFFFFF;
	}
	else
	{
		if (mlx->c_color == 0x000000)
			mlx->c_color = 0xFFFFFF;
		else
			mlx->c_color = 0x000000;
	}
}

int				goaway(void)
{
	// system("leaks fractol");
	exit(0);
	return (0);
}

void	pixel_put_to_image(t_mlx_ptr *mlx, int x, int y, int color)
{
	if (y < WIDTH && x < HEIGHT)
		*(mlx->img_ptr + WIDTH * y + x) = color;
}

void	put_color(t_mlx_ptr *mlx)
{
	if (mlx->iter >= mlx->max_iter)
		pixel_put_to_image(mlx, mlx->x,mlx->y, mlx->c_color);
	else
		pixel_put_to_image(mlx, mlx->x,mlx->y, mlx->color * mlx->iter);
}

void	print_burning_ship(t_mlx_ptr *mlx)
{
	double	x_new;

	while (mlx->z.re * mlx->z.re + mlx->z.im * mlx->z.im < 4 
		&& mlx->iter < mlx->max_iter)
	{
		x_new = mlx->z.re * mlx->z.re - mlx->z.im * mlx->z.im + mlx->c.re;
		mlx->z.im = fabs(2 * mlx->z.re * mlx->z.im) + mlx->c.im;
		mlx->z.re = fabs(x_new);
		mlx->iter++;
	}
}
