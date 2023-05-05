/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:58:13 by nait-ali          #+#    #+#             */
/*   Updated: 2023/05/05 04:46:29 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	hooks_bonus(t_data *img)
{
	mlx_hook(img->mlx_win, 17, 0, close_window, (void *)img);
	mlx_hook(img->mlx_win, 2, 0, touche_clavier_bonus, (void *)img);
	mlx_hook(img->mlx_win, 4, 0, touche_mouse_bonus, (void *)img);
}

void	hooks_julia_bonus(t_data *img)
{
	mlx_hook(img->mlx_win, 17, 0, close_window, (void *)img);
	mlx_hook(img->mlx_win, 2, 0, touche_clavier2_bonus, (void *)img);
	mlx_hook(img->mlx_win, 4, 0, touche_mouse2_bonus, (void *)img);
}

void	hooks_tricorn(t_data *img)
{
	mlx_hook(img->mlx_win, 17, 0, close_window, (void *)img);
	mlx_hook(img->mlx_win, 2, 0, touche_clavier3, (void *)img);
	mlx_hook(img->mlx_win, 4, 0, touche_mouse3, (void *)img);
}

int	main(int argc, char **argv)
{
	t_data	mlx;

	mlx.mlx = 0;
	if (argc == 2)
	{
		if ((ft_strcmp(argv[1], "mandelbrot")))
			mandelbrot_bonus(mlx);
		else if ((ft_strcmp(argv[1], "julia")))
			julia_bonus(mlx);
		else if ((ft_strcmp(argv[1], "tricorn")))
			tricorn(mlx);
		else
		{
			ft_putstr("le parametre n'est pas valide !!!.");
			return (0);
		}
	}
	else
		rappel_bonus();
	return (0);
}
