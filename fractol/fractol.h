/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 03:52:23 by nait-ali          #+#    #+#             */
/*   Updated: 2023/04/24 22:57:03 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    FRACTOL_H
# define    FRACTOL_H

# include<unistd.h>
# include<stdlib.h>
# include<mlx.h>
# include <stdio.h>
# define LARGEUR  1000;
# define LANGEUR  1000;
# define MAX_ITERATION 70;

typedef struct nbr_complexe {
	double	a;
	double	b;
}t_complexe;

typedef struct mlx_data {
	void		*mlx;
	void		*ptr;
	void		*window;
	void		*img;
	char		*addr;
	void		*img_ptr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
	char		*param;
	int			reelmax;
	int			reelmin;
	double		imaginairemax;
	double		imaginairemin;
	int			*addresse;
	int			iteration;
	int			couleur;
	int			couleur2;
	t_complexe	z;
	t_complexe	c;
	t_complexe	tm;

}t_mlx_data;

int		close_window(t_mlx_data *mlx);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *s);
void	mandelbrot_init(t_mlx_data *mlx);
void	f_mandelbrot(t_mlx_data *mlx);
void	mandelbrot_draw(t_mlx_data	*mlx);
void	mandelbrot_calcul(t_mlx_data *mlx, int x, int y);
// void	my_mlx_pixel_put(int x, int y, int *str, int clr);
void	my_mlx_pixel_put(t_mlx_data *mlx, int x, int y, int color);

#endif
