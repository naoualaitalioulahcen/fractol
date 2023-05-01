#include "fractol.h"
int	close_window(t_data *mlx)
{
	exit(0);
}



int	touche_clavier(int keycode, t_data	*img)
{
	if (keycode == 53)
		exit(0);

	return (0);
}

int	touche_mouse(int keycode,int x,int y,t_data *img)
{
	
    if (keycode == 1 && img->id == 1)
    {
        img->x = x;
        img->y = y;
        julia_draw(img);
    }
    
    if (keycode == 5)
    {
        img->range += 0.1;
        // tasghir
        // img->max_iteration -= 1.5;
    }
    if (keycode == 4)
    {
   
        img->range -= 0.1;
        // takbir
        // img->max_iteration += 1.5;
    }
     mandelbrot_draw(img);
    printf("mlx->range = %.6f\n", img->range);fflush(stdout);
    // mlx->range =2;
    // mandelbrot_draw(mlx);
    // printf ("rmax = %f ,rmin = %f\n", mlx->rmax, mlx->rmin);
    return (0);
}

void	hooks(t_data *img)
{
	mlx_hook(img->mlx_win, 17, 0, close_window, (void *)img);
	// mlx_hook(img->mlx_win, 6, 0, mouve_mouse, (void *)img);
	mlx_hook(img->mlx_win, 2, 0, touche_clavier, (void *)img);
	
	mlx_hook(img->mlx_win, 4, 0, touche_mouse, (void *)img);
	// mlx_mouse_hook(mlx->mlx_win, &touche_mouse, (void *)mlx);
	
}
// int mouve_mouse(t_data mlx,double x, double y)
// {
// 	mlx.x =x;
// 	mlx.y =y;
// 	julia_draw(mlx,mlx.x,mlx.y);
// 	return (0);
// }

void	hooks_julia(t_data *img)
{
	mlx_hook(img->mlx_win, 17, 0, close_window, (void *)img);
	mlx_hook(img->mlx_win, 2, 0, touche_clavier, (void *)img);
	mlx_hook(img->mlx_win, 4, 0, touche_mouse2, (void *)img);
}

int	touche_mouse2(int keycode,int x,int y,t_data *img)
{
    if (keycode == 1)
    {
        img->x = img->rmin + ((x   * img->range) / img->width);
        img->y = (img->rmin + (y   * img->range) / img->height) * -1 ;
        julia_draw(img);
    }
    return(0);
}


