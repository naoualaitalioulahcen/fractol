/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_couleurs_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:04:48 by nait-ali          #+#    #+#             */
/*   Updated: 2023/05/05 04:44:57 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= data->width || x < 0 || y >= data->height)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	couleur(t_data *mlx)
{
	double	i;
	double	r;
	double	g;
	double	b;

	i = mlx->iteration / mlx->max_iteration;
	b = 900 * i * i * i * (1 - i);
	g = 400 * i * i * (1 - i) * (1 - i);
	r = 100 * i * (1 - i) * (1 - i) * (1 - i);
	return (chifting_color(mlx, r, g, b));
}

int	chifting_color(t_data *mlx, int r, int g, int b)
{
	if (mlx->flag == 0)
		return (0 << 24 | r << 16 | g << 8 | b);
	else if (mlx->flag == 1)
		return (0 << 24 | r << 16 | b << 8 | g);
	else if (mlx->flag == 2)
		return (0 << 24 | b << 16 | r << 8 | g);
	else if (mlx->flag == 3)
		return (0 << 24 | b << 16 | g << 8 | r);
	else if (mlx->flag == 4)
		return (0 << 24 | g << 16 | r << 8 | b);
	if (mlx->flag == 5)
		return (0 << 24 | g << 16 | b << 8 | r);
	else if (mlx->flag == 6)
	{
		mlx->flag = 0;
		return (0 << 24 | r << 16 | g << 8 | b);
	}
	return (0);
}
