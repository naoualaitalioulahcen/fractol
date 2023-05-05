/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:06:09 by nait-ali          #+#    #+#             */
/*   Updated: 2023/05/05 04:17:50 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include <stdio.h>

typedef struct nbr_complexe
{
	double	a;
	double	b;
}t_complexe;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	rmax;
	double	imax;
	double	rmin;
	double	imin;
	int		width;
	int		height;
	void	*mlx;
	void	*mlx_win;
	double	max_iteration;
	double	x;
	double	y;
	double	iteration;
	int		flag;

}				t_data;

void	hooks_bonus(t_data *img);
void	hooks_julia_bonus(t_data *img);
void	hooks_tricorn(t_data *img);
int		mandelbrot_calcul_bonus(t_data *mlx, double x, double y);
void	mandelbrot_draw_bonus(t_data	*img);
int		mandelbrot_bonus(t_data	img);
void	initialisation_range(t_data *img);
void	rappel_bonus(void);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *s);
int		julia_calcul_bonus(t_data *mlx, double x, double y);
void	julia_draw_bonus(t_data *img);
int		julia_bonus(t_data	img);
int		chifting_color(t_data *mlx, int r, int g, int b);
int		couleur(t_data *mlx);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		touche_clavier3(int keycode, t_data	*img);
int		touche_mouse3(int keycode, int x, int y, t_data *img);
int		close_window(t_data *mlx);
int		touche_clavier_bonus(int keycode, t_data	*img);
int		touche_mouse_bonus(int keycode, int x, int y, t_data *img);
int		zoom(int keycode, int x, int y, t_data *img);
int		touche_mouse2_bonus(int keycode, int x, int y, t_data *img);
int		touche_clavier2_bonus(int keycode, t_data	*img);
int		tricorn_calcul(t_data *mlx, double x, double y);
void	tricorn_draw(t_data	*img);
int		tricorn(t_data	img);
void	rappel(void);
int		touche_clavier(int keycode, t_data	*img);
int		touche_mouse(int keycode, int x, int y, t_data *img);
void	hooks(t_data *img);
int		mandelbrot_calcul(t_data *mlx, double x, double y);
void	mandelbrot_draw(t_data	*img);
int		touche_clavier2(int keycode, t_data	*img);
int		mandelbrot(t_data	img);
int		julia_calcul(t_data *mlx, double x, double y);
void	julia_draw(t_data	*img);
int		julia(t_data	img);
int		mouve_mouse(t_data mlx, double x, double y);
void	hooks_julia(t_data *img);
int		touche_mouse2(int keycode, int x, int y, t_data *img);
int		tricorn_mouse3(int keycode, int x, int y, t_data *img);

#endif
