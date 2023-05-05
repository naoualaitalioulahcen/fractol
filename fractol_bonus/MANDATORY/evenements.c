/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evenements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:55:36 by nait-ali          #+#    #+#             */
/*   Updated: 2023/05/05 03:50:54 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_window(t_data *mlx)
{
	(void )mlx;
	exit(0);
}

int	touche_clavier(int keycode, t_data	*img)
{
	(void )img;
	if (keycode == 53)
		exit(0);
	return (0);
}

int	touche_mouse(int keycode, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	if (keycode == 5)
	{
		img->imax = 0.8 * img->imax;
		img->imin = 0.8 * img->imin;
		img->rmax = 0.8 * img->rmax ;
		img->rmin = 0.8 * img->rmin ;
	}
	if (keycode == 4)
	{
		img->imax = 1.2 * img->imax;
		img->imin = 1.2 * img->imin;
		img->rmax = 1.2 * img->rmax ;
		img->rmin = 1.2 * img->rmin;
	}
	mandelbrot_draw(img);
	return (0);
}



int	touche_mouse2(int keycode, int x, int y, t_data *img)
{
	if (keycode == 1 || keycode == 2)
	{
		img->x = img->rmin + ((x * (img->rmax - img->rmin)) / img->width);
		img->y = img->imax + \
		((y * (img->imax - img->imin)) / img->height) * -1 ;
		julia_draw(img);
	}
	if (keycode == 5)
	{
		img->imax = 0.8 * img->imax;
		img->imin = 0.8 * img->imin;
		img->rmax = 0.8 * img->rmax ;
		img->rmin = 0.8 * img->rmin ;
	}
	if (keycode == 4)
	{
		img->imax = 1.2 * img->imax;
		img->imin = 1.2 * img->imin;
		img->rmax = 1.2 * img->rmax ;
		img->rmin = 1.2 * img->rmin;
	}
	julia_draw(img);
	return (0);
}
