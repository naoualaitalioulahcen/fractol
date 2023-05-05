/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:57:55 by nait-ali          #+#    #+#             */
/*   Updated: 2023/05/05 04:37:50 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	julia_calcul(t_data *mlx, double x, double y)
{
	t_complexe	c;
	t_complexe	z;
	t_complexe	tm;
	int			iteration;

	iteration = 1;
	z.a = mlx->rmin + ((x * (mlx->rmax - mlx->rmin)) / mlx->width);
	z.b = mlx->imax + ((y * (mlx->imax - mlx->imin)) / mlx->height) * -1 ;
	c.a = mlx->x;
	c.b = mlx->y;
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

void	julia_draw(t_data *img)
{
	double	x;
	double	y;

	mlx_clear_window(img->mlx, img->mlx_win);
	y = 0;
	while (y++ < img->height)
	{
		x = 0;
		while (x++ < img->width)
		{
			img->iteration = julia_calcul(img, x, y);
			if (img->iteration == img->max_iteration)
			{
				my_mlx_pixel_put(img, x, y, 0x000000);
			}
			else
			{
				my_mlx_pixel_put(img, x, y, 10 * img->iteration);
			}
		}
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

int	julia(t_data	img)
{
	img.width = 500 ;
	img.height = 500;
	img.max_iteration = 50;
	initialisation_range(&img);
	img.x = 0.3;
	img.y = 0.5;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.width, img.height, "julia");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	julia_draw(&img);
	hooks_julia(&img);
	mlx_loop(img.mlx);
	return (0);
}
