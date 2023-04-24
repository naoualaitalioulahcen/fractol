/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 03:53:07 by nait-ali          #+#    #+#             */
/*   Updated: 2023/04/24 22:59:03 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rappel(void)
{
	ft_putstr(" le nombre de parametres n'est pas correct!\n ");
	ft_putstr("si vous voulez afficher mandelbrot ecrire :\n     mandelbrot\n");
	ft_putstr(" si vous voulez afficher mandelbrot ecrire :\n     julia\n");
}

void	hooks(t_mlx_data *mlx)
{
	mlx_hook(mlx->window, 17, 0, close_window, (void *)mlx);
}

int	main(int argc, char **argv)
{
	t_mlx_data	*mlx;

	mlx = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	if (!mlx)
		exit(-1);
	if (argc == 2)
	{
		if ((ft_strcmp(argv[1], "mandelbrot")))
			mandelbrot_draw(mlx);
		// else if ((ft_strcmp(argv[1], "j")))
		// 	f_julia(mlx);
		else
		{
			ft_putstr("le parametre n'est pas valide !!!.");
			return (0);
		}
		hooks(mlx);
		mlx_loop(mlx);
	}
	else
		rappel();
	free(mlx);
	return (0);
}
