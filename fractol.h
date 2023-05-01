#ifndef FRACTOL_H
#define FRACTOL_H

#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>


typedef struct nbr_complexe
{
	double a;
	double b;
} t_complexe;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    double rmax;
	double imax;
	double rmin;
	double imin;
    double range;
    int width;
    int height;
    void	*mlx;
	void	*mlx_win;
    double max_iteration;
	double	x;
	double y;
	int id;

}				t_data;

void	ft_putstr(char *s);
int	ft_strcmp(char *s1, char *s2);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	rappel(void);
int	close_window(t_data *mlx);
int	touche_clavier(int keycode, t_data	*img);
int	touche_mouse(int keycode,int x,int y,t_data *img);
void	hooks(t_data *img);
int mandelbrot_calcul(t_data *mlx, double x, double y);
void	mandelbrot_draw(t_data	*img);
int	mandelbrot(t_data	img);
int julia_calcul(t_data *mlx, double x, double y);
void	julia_draw(t_data	*img);
int	julia(t_data	img);
int mouve_mouse(t_data mlx,double x, double y);
void	hooks_julia(t_data *img);
int	touche_mouse2(int keycode,int x,int y,t_data *img);





#endif