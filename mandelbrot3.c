/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:58:48 by itishche          #+#    #+#             */
/*   Updated: 2019/04/01 12:58:50 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_fractol.h"

void	original_madelbrot(t_mlx_ptr *mlx)
{
	double	x_new;

	while (mlx->z.re * mlx->z.re + mlx->z.im * mlx->z.im < 4 
		&& mlx->iter < mlx->max_iter)
	{
		x_new = mlx->z.re * mlx->z.re - mlx->z.im * mlx->z.im + mlx->c.re;
		mlx->z.im = 2 * mlx->z.re * mlx->z.im + mlx->c.im;
		mlx->z.re = x_new;
		mlx->iter++;
	}
}

void	madelbrot2(t_mlx_ptr *mlx)
{
	double	x_new;

	while (mlx->z.re * mlx->z.re + mlx->z.im * mlx->z.im < 4 
		&& mlx->iter < mlx->max_iter)
	{
		x_new = mlx->z.re * mlx->z.re * mlx->z.re - 3 * mlx->z.re *
			mlx->z.im * mlx->z.im + mlx->c.re;
		mlx->z.im = 3 * mlx->z.re * mlx->z.re * mlx->z.im  - mlx->z.im *
			mlx->z.im * mlx->z.im + mlx->c.im;
		mlx->z.re = x_new;
		mlx->iter++;
	}
}

void	madelbrot3(t_mlx_ptr *mlx)
{
	double	x_new;

	while (mlx->z.re * mlx->z.re + mlx->z.im * mlx->z.im < 4 
		&& mlx->iter < mlx->max_iter)
	{
		x_new = -4 * mlx->z.re * mlx->z.im *
			(mlx->z.re * mlx->z.re - mlx->z.im * mlx->z.im) + mlx->c.re;
		mlx->z.im = mlx->z.re * mlx->z.re * mlx->z.re * mlx->z.re +
			mlx->z.im * mlx->z.im * mlx->z.im * mlx->z.im -
			6 * mlx->z.re * mlx->z.re * mlx->z.im * mlx->z.im + mlx->c.im;
		mlx->z.re = x_new;
		mlx->iter++;
	}
}

void	flyingsquirrel(t_mlx_ptr *mlx)
{
	double	x_new;

	while (mlx->z.re * mlx->z.re + mlx->z.im * mlx->z.im < 4 
		&& mlx->iter < mlx->max_iter)
	{
		x_new = (mlx->z.re * mlx->z.re - 3.0 * mlx->z.im * mlx->z.im)
			* mlx->z.re + mlx->c.re;
		mlx->z.im =	fabs((3.0 * mlx->z.re * mlx->z.re - mlx->z.im *
			mlx->z.im) * mlx->z.im) + mlx->c.im;
		mlx->z.re = x_new;
		mlx->iter++;
	}
}

void	mandelbar(t_mlx_ptr *mlx)
{
	double	x_new;

	while (mlx->z.re * mlx->z.re + mlx->z.im * mlx->z.im < 4 
		&& mlx->iter < mlx->max_iter)
	{
		x_new = 4 * mlx->z.re * mlx->z.im * (mlx->z.re * mlx->z.re -
			mlx->z.im * mlx->z.im) + mlx->c.re;
		mlx->z.im = mlx->z.re * mlx->z.re * mlx->z.re * mlx->z.re +
			mlx->z.im * mlx->z.im * mlx->z.im * mlx->z.im - 6 * mlx->z.re *
			mlx->z.re * mlx->z.im * mlx->z.im + mlx->c.im;	
		mlx->z.re = x_new;
		mlx->iter++;
	}
}
