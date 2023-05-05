/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:58:13 by nait-ali          #+#    #+#             */
/*   Updated: 2023/05/05 04:43:25 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	hooks(t_data *img)
{
	mlx_hook(img->mlx_win, 17, 0, close_window, (void *)img);
	mlx_hook(img->mlx_win, 2, 0, touche_clavier, (void *)img);
	mlx_hook(img->mlx_win, 4, 0, touche_mouse, (void *)img);
}
void	hooks_julia(t_data *img)
{
	mlx_hook(img->mlx_win, 17, 0, close_window, (void *)img);
	mlx_hook(img->mlx_win, 2, 0, touche_clavier, (void *)img);
	mlx_hook(img->mlx_win, 4, 0, touche_mouse2, (void *)img);
}

int	main(int argc, char **argv)
{
	t_data	mlx;

	mlx.mlx = 0;
	if (argc == 2)
	{
		if ((ft_strcmp(argv[1], "mandelbrot")))
			mandelbrot(mlx);
		else if ((ft_strcmp(argv[1], "julia")))
			julia(mlx);
		else
		{
			ft_putstr("le parametre n'est pas valide !!!.");
			return (0);
		}
	}
	else
		rappel();
	//mlx_loop(mlx.mlx);
	return (0);
}
