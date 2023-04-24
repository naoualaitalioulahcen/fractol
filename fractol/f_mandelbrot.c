/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_mandelbrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 03:51:59 by nait-ali          #+#    #+#             */
/*   Updated: 2023/04/24 22:58:29 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	mandelbrot_calcul(t_mlx_data *mlx, int x, int y)
{
	double	reel_range;
	double	imaginaire_range;

	reel_range = mlx->reelmax - mlx->reelmin;
	imaginaire_range = mlx->imaginairemax - mlx->imaginairemin;
	mlx->iteration = 1;
	mlx->c.a = mlx->reelmin + x / 1000 * reel_range;
	mlx->c.b = mlx->imaginairemin + y / 1000 * imaginaire_range;
	mlx->z.a = 0.0;
	mlx->z.b = 0.0;
	mlx->tm = mlx->z;
	while (mlx->z.a * mlx->z.a + mlx->z.b * mlx->z.b < 4 \
	&& mlx->iteration < 70)
	{
		mlx->tm.a = mlx->z.a * mlx->z.a - mlx->z.b * mlx->z.b + mlx->c.b;
		mlx->tm.b = 2 * mlx->z.a * mlx->z.b + mlx->c.b;
		mlx->z = mlx->tm;
		mlx->iteration++;
	}
}

void	mandelbrot_draw(t_mlx_data	*mlx)
{
	int	x;
	int	y;

	y = 0;
	mandelbrot_init(mlx);
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			mandelbrot_calcul(mlx, x, y);
			if (mlx->iteration == 70)
				mlx->couleur = mlx->couleur2;
			else
				mlx->couleur = mlx->couleur2 * mlx->iteration;
			my_mlx_pixel_put(mlx, x , y, 0x00ffFFFF);
			// my_mlx_pixel_put(x, y, mlx->addresse, 0x00FF0000);
			x++;
		}
		y++;
	}
	printf("[0]\n");fflush(stdout);
	mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img_ptr, 0, 0);
	printf("[1]\n");fflush(stdout);
}

// void	f_mandelbrot(t_mlx_data *mlx)
// {
// 	mandelbrot_init(mlx);
// 	mandelbrot_draw(mlx);
// }
