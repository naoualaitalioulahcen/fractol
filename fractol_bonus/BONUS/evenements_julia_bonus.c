/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evenements_julia_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:03:58 by nait-ali          #+#    #+#             */
/*   Updated: 2023/05/05 04:49:26 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	zoom(int keycode, int x, int y, t_data *img)
{
	double	z;
	double	g;

	z = img->rmin + ((x * (img->rmax - img->rmin)) / img->width);
	g = img->imax + ((y * (img->imax - img->imin)) / img->height) * -1 ;
	if (keycode == 5)
	{
		img->imax = 0.8 * (img->imax - g) + g;
		img->imin = 0.8 * (img->imin - g) + g;
		img->rmax = 0.8 * (img->rmax - z) + z;
		img->rmin = 0.8 * (img->rmin - z) + z;
		img ->max_iteration += 9;
	}
	if (keycode == 4)
	{
		img->imax = 1.2 * (img->imax - g) + g;
		img->imin = 1.2 * (img->imin - g) + g;
		img->rmax = 1.2 * (img->rmax - z) + z;
		img->rmin = 1.2 * (img->rmin - z) + z;
		if (img->max_iteration < 45)
			img->max_iteration = 45;
		else
			img->max_iteration -= 9;
	}
	return (0);
}

int	touche_mouse2_bonus(int keycode, int x, int y, t_data *img)
{
	if (keycode == 1 || keycode == 2)
	{
		img->x = img->rmin + ((x * (img->rmax - img->rmin)) / img->width);
		img->y = img->imax + \
		((y * (img->rmax - img->rmin)) / img->height) * -1 ;
	}
	zoom(keycode, x, y, img);
	return (julia_draw_bonus(img), 0);
}

int	touche_clavier2_bonus(int keycode, t_data	*img)
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
	return (julia_draw_bonus(img), 0);
}
