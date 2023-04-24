/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   les_outils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 03:52:43 by nait-ali          #+#    #+#             */
/*   Updated: 2023/04/24 22:57:36 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	mandelbrot_init(t_mlx_data *mlx)
{
	mlx->x = 0;
	mlx->y = 0;
	mlx->reelmin = -2;
	mlx->reelmax = 2;
	mlx->imaginairemin = -2;
	mlx->imaginairemax = 2;
	mlx->ptr = mlx_init();
	mlx->couleur = 0x0000FF00;
	mlx->couleur2 = 0x0000FF00;
	mlx->param = "mandelbrot";
	mlx->window = mlx_new_window(mlx->ptr, 1000, 1000, "mandelbrot");
	mlx->img_ptr = mlx_new_image(mlx->ptr, 1000, 1000);
	mlx->addr = mlx_get_data_addr(mlx->img_ptr, \
	&(mlx->bits_per_pixel), &(mlx->line_length), &(mlx->endian));
}

// void	my_mlx_pixel_put(int x, int y, int *str, int clr)
// {
// 	pixel = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
// 		*(unsigned int*)pixel = clr;
// }
void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
char	*dst;
	if (x < 0 || x >= 1000 || y < 0 ||y >= 1000)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	// printf("x= %d , y = %d line_length = %d bits_per_pixel = %d\n", x , y, mlx->line_length,mlx ->bits_per_pixel);
	// fflush(stdout);


}
// void	my_mlx_pixel_put(t_mlx_data *mlx, int x, int y, int color)
// {
//     int     pixel;

//     pixel = (y * mlx->line_length) + (x * (mlx->bits_per_pixel / 8));
//     mlx->data[pixel] = color;
//     mlx->data[pixel + 1] = color >> 8;
//     mlx->data[pixel + 2] = color >> 16;
// }

