/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evenements_mandelbrot_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:55:36 by nait-ali          #+#    #+#             */
/*   Updated: 2023/05/05 04:44:46 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_window(t_data *mlx)
{
	(void )mlx;
	exit(0);
}

int	touche_clavier_bonus(int keycode, t_data	*img)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 123)
	{
		img->rmin += 0.1;
		img->rmax += 0.1;
	}
	else if (keycode == 124)
	{
		img->rmax -= 0.1;
		img->rmin -= 0.1;
	}
	else if (keycode == 125)
	{
		img->imax += 0.1;
		img->imin += 0.1;
	}
	else if (keycode == 126)
	{
		img->imax -= 0.1;
		img->imin -= 0.1;
	}
	else if (keycode == 49)
		img->flag++;
	return (mandelbrot_draw_bonus(img), 0);
}

int	touche_mouse_bonus(int keycode, int x, int y, t_data *img)
{
	zoom(keycode, x, y, img);
	mandelbrot_draw_bonus(img);
	return (0);
}
