/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:46:17 by itishche          #+#    #+#             */
/*   Updated: 2019/03/25 10:46:19 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_fractol.h"

void		init_help_window(t_nmlx *h)
{
	mlx_string_put(h->mlx_ptr, h->win_ptr, 0, 0, 0xFFFFFF, "1 - Mandelbrot");
	mlx_string_put(h->mlx_ptr, h->win_ptr, 0, 17, 0xFFFFFF, "2 - Julia");
	mlx_string_put(h->mlx_ptr, h->win_ptr, 0, 34, 0xFFFFFF, "3 - Burning ship");
	mlx_string_put(h->mlx_ptr, h->win_ptr, 0, 51, 0xFFFFFF, "4 - Mandelbrot x2");
	mlx_string_put(h->mlx_ptr, h->win_ptr, 0, 68, 0xFFFFFF, "5 - Mandelbrot x3");
	mlx_string_put(h->mlx_ptr, h->win_ptr, 0, 85, 0xFFFFFF, "6 - Flying squirrel");
	mlx_string_put(h->mlx_ptr, h->win_ptr, 0, 102, 0xFFFFFF, "7 - Mandelbar 4th order");
	mlx_string_put(h->mlx_ptr, h->win_ptr, 0, 119, 0xFFFFFF, "----- Mouse hooks");
	mlx_string_put(h->mlx_ptr, h->win_ptr, 0, 136, 0xFFFFFF, "Sroll up/down - zoom follow the actual mouse position");
	mlx_string_put(h->mlx_ptr, h->win_ptr, 0, 153, 0xFFFFFF, "----- Key hooks");
	mlx_string_put(h->mlx_ptr, h->win_ptr, 0, 170, 0xFFFFFF, "M - lock/unlock mouse for Julia");
	mlx_string_put(h->mlx_ptr, h->win_ptr, 0, 187, 0xFFFFFF, "Arrows - moving");
	mlx_string_put(h->mlx_ptr, h->win_ptr, 0, 204, 0xFFFFFF, "+/-  correct the number of iterations");
	mlx_string_put(h->mlx_ptr, h->win_ptr, 0, 221, 0xFFFFFF, "1-7 change fractals");
	mlx_string_put(h->mlx_ptr, h->win_ptr, 0, 238, 0xFFFFFF, "if you choose the same fractal - it's return you to");
	mlx_string_put(h->mlx_ptr, h->win_ptr, 0, 255, 0xFFFFFF, "the default position");
}


void		init_window(t_mlx_ptr *mlx, t_nmlx *help)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, HEIGHT, WIDTH, "FRACTOL");
	help->mlx_ptr = mlx_init();
	help->win_ptr = mlx_new_window(mlx->mlx_ptr, 600, 500, "Help window");
	init_help_window(help);
	mlx->img = mlx_new_image(mlx->mlx_ptr, HEIGHT, WIDTH);
	mlx->img_ptr = (int*)mlx_get_data_addr(mlx->img,
		&mlx->bit_per_pix, &mlx->size_line, &mlx->endian);
}

void		check_fract(t_mlx_ptr *mlx)
{
	if (mlx->number_fract == 2)
		print_julia(mlx);
	else
		print_mandelbrot(mlx);
}

void	init_mlx_struct(t_mlx_ptr *mlx, char **argv)
{
	if (ft_strcmp(argv[1], "1") == 0)
		mlx->number_fract = 1;
	else if (ft_strcmp(argv[1], "2") == 0)
		mlx->number_fract = 2;
	else if (ft_strcmp(argv[1], "3") == 0)
		mlx->number_fract = 3;
	else if (ft_strcmp(argv[1], "4") == 0)
		mlx->number_fract = 4;
	else if (ft_strcmp(argv[1], "5") == 0)
		mlx->number_fract = 5;
	else if (ft_strcmp(argv[1], "6") == 0)
		mlx->number_fract = 6;
	else if (ft_strcmp(argv[1], "7") == 0)
		mlx->number_fract = 7;
	if (mlx->number_fract == 2)
		init_julia(mlx);	
	else
		init_mandelbrot(mlx);
	
}

int		main(int argc, char **argv)
{
	t_mlx_ptr	mlx;
	t_nmlx		help;

	if (argc != 2 || argv[1][1] != '\0' || (argv[1][0] != '1' && argv[1][0] != '2'
		&& argv[1][0] != '3' && argv[1][0] != '4'
		&& argv[1][0] != '5' && argv[1][0] != '6' && argv[1][0] != '7'))
	{
		ft_putstr("usage: ./fractol\n1 - Mandelbrot\n2 - Julia\n3 - Burning ship\n");
		ft_putstr("4 - Mandelbrot x2\n5 - Mandelbrot x3\n6 - Flying squirrel\n");
		ft_putstr("7 - Mandelbar 4th order\n");
		return (0);
	}
	init_window(&mlx,&help);
	init_mlx_struct(&mlx, argv);
	check_fract(&mlx);
	mlx_hook(mlx.win_ptr, 17,  1L << 17, goaway, &mlx);
	mlx_hook(mlx.win_ptr, 2, 0, key_function, &mlx);
	mlx_hook(mlx.win_ptr, 6, 1L < 6, mouse_julia, &mlx);
	mlx_hook(mlx.win_ptr, 4, 0, mouse_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
