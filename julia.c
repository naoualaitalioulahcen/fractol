# include "fractol.h"

int julia_calcul(t_data *mlx, double x, double y)
{
    t_complexe c;
    t_complexe z;
    t_complexe tm;
	int iteration = 1;
	z.a = mlx->rmin + ((x   * mlx->range) / mlx->width);
	z.b = (mlx->rmin + (y   * mlx->range) / mlx->height) * -1 ;
	c.a = mlx->x;
	c.b = mlx->y;
    tm = z;
	while ((z.a * z.a + z.b * z.b) < 4 && iteration < mlx->max_iteration)
	{
		tm.a = z.a * z.a - z.b * z.b + c.a;
		tm.b = 2 * z.a * z.b + c.b;
		z = tm;
		iteration++;
	}
    return(iteration);
}


void	julia_draw(t_data	*img)
{
	double	x;
	double	y;
	mlx_clear_window(img->mlx,img->mlx_win);
	
	img->rmax=img->range /2;
	img->rmin =-img->range /2;
	img->imax =img->range /2;
	img->imin = -img->range /2;

    int iteration;
    int couleur;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			
			iteration = julia_calcul(img,x,y);
			if (iteration == 150)
			{
				couleur = 0x000000;
				my_mlx_pixel_put(img, x , y, couleur);
			}
			else
		    {
				couleur =  10;
				my_mlx_pixel_put(img, x , y, couleur * iteration);
			}
			x++;

		}
		y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

int	julia(t_data	img)
{
    img.width = 500 ;
    img.height = 500;
    img.max_iteration = 80;
    img.range = 2.0;
    img.x = 0.3;
    img.y = 0.5;
    img.id = 2;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.width,  img.height, "julia");
	img.img = mlx_new_image(img.mlx, img.width,  img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    julia_draw(&img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
    hooks_julia(&img);
	mlx_loop(img.mlx);
    return(0);

}

