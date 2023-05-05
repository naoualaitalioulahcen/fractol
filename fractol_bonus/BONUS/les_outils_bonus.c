/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   les_outils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:55:59 by nait-ali          #+#    #+#             */
/*   Updated: 2023/05/05 04:45:10 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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

void	rappel_bonus(void)
{
	ft_putstr("\tle nombre de parametres n'est pas correct!\n ");
	ft_putstr("\tsi vous voulez afficher mandelbrot ecrire :\n\tmandelbrot\n");
	ft_putstr("\tsi vous voulez afficher julia ecrire :\n\tjulia\n");
	ft_putstr("\tsi vous voulez afficher un autre fractal ecrire :\n \ttricorn\n");
}

void	initialisation_range(t_data *img)
{
	img->rmax = 2;
	img->rmin = -2;
	img->imax = 2;
	img->imin = -2;
}
