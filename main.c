#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	mlx;

	// mlx = (t_data *)malloc(sizeof(t_data));
	// if (!mlx)
	// 	exit(-1);
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
		// hooks(mlx);
		// hooks(mlx);
		// _loop(mlx);mlx
	}
	else
		rappel();
	// free(mlx);
	return (0);
}
