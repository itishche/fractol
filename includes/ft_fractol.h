/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:46:56 by itishche          #+#    #+#             */
/*   Updated: 2019/03/25 10:47:00 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <math.h>
# include "/Users/tishchenko/minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define HEIGHT 1080
# define WIDTH 1080

typedef struct			s_complex
{
	double				re;
	double				im;
}						t_complex;

typedef struct			s_nmlx
{
	void				*mlx_ptr;
	void				*win_ptr;
}						t_nmlx;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img;
	int					*img_ptr;
	int					color;
	int					x;
	int					y;
	int					mouse_on_off;
	int					max_iter;
	int					iter;
	int					number_fract;
	int					bit_per_pix;
	int					size_line;
	int					endian;
	t_complex			c;
	t_complex			z;
	double				zoom;
	double				start_x;
	double				start_y;

}						t_mlx_ptr;

void					put_color(t_mlx_ptr *mlx);
int						goaway(void);
void					check_fract(t_mlx_ptr *mlx);
void					pixel_put_to_image(t_mlx_ptr *mlx, int x, int y, int color);

void					print_mandelbrot(t_mlx_ptr *mlx);
void					init_mandelbrot(t_mlx_ptr *mlx);
void					original_madelbrot(t_mlx_ptr *mlx);
void					madelbrot2(t_mlx_ptr *mlx);
void					madelbrot3(t_mlx_ptr *mlx);
void					flyingsquirrel(t_mlx_ptr *mlx);
void					mandelbar(t_mlx_ptr *mlx);
void					print_julia(t_mlx_ptr *mlx);
void					init_julia(t_mlx_ptr *mlx);
int						mouse_julia(int x, int y, t_mlx_ptr *mlx);
void					print_burning_ship(t_mlx_ptr *mlx);
int						key_function(int keycode, t_mlx_ptr *mlx);
void					zoooom(int x, int y, t_mlx_ptr *mlx);
void					azoooom(int x, int y, t_mlx_ptr *mlx);
int						mouse_hook(int button, int x, int y, t_mlx_ptr *mlx);

void					*ft_memcpy(void *dst, void *src, size_t n);
void					ft_putstr(char *s);
int						ft_strcmp(char *s1, char *s2);
void					ft_bzero(void *str, size_t n);
#endif

