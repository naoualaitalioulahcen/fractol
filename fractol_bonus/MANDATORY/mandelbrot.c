/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:56:14 by nait-ali          #+#    #+#             */
/*   Updated: 2023/05/05 04:37:55 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot_calcul(t_data *mlx, double x, double y)
{
	t_complexe	c;
	t_complexe	z;
	t_complexe	tm;
	int			iteration;

	iteration = 1;
	c.a = mlx->rmin + (x * (mlx->rmax - mlx->rmin)) / mlx->width;
	c.b = mlx->imax + (y * (mlx->imax - mlx->imin) / mlx->height) * -1 ;
	z.a = 0.0;
	z.b = 0.0;
	tm = z;
	while ((z.a * z.a + z.b * z.b) < 4 && iteration < mlx->max_iteration)
	{
		tm.a = z.a * z.a - z.b * z.b + c.a;
		tm.b = 2 * z.a * z.b + c.b;
		z = tm;
		iteration++;
	}
	return (iteration);
}

void	mandelbrot_draw(t_data	*img)
{
	double	x;
	double	y;

	mlx_clear_window(img->mlx, img->mlx_win);
	y = 1;
	while (y++ < img->height)
	{
		x = 1;
		while (x++ < img->width)
		{
			img->iteration = mandelbrot_calcul(img, x, y);
			if (img->iteration == img->max_iteration)
			{
				my_mlx_pixel_put(img, x, y, 0);
			}
			else
			{
				my_mlx_pixel_put(img, x, y, 10 * img->iteration);
			}
		}
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

int	mandelbrot(t_data	img)
{
	img.width = 500 ;
	img.height = 500;
	img.max_iteration = 50;
	initialisation_range(&img);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.width, img.height, "Mandelbrot");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	mandelbrot_draw(&img);
	hooks(&img);
	mlx_loop(img.mlx);
	return (0);
}
