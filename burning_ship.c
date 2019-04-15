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
		pixel_put_to_image(mlx, mlx->x,mlx->y, 0x000000);
	else
		pixel_put_to_image(mlx, mlx->x,mlx->y,  0x2A0FFF * mlx->iter);
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
