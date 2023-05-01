# include "fractol.h"

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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	if (x < 0 || x >= 1000 || y < 0 ||y >= 1000)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;

}
void	rappel(void)
{
	ft_putstr("\tle nombre de parametres n'est pas correct!\n ");
	ft_putstr("\tsi vous voulez afficher mandelbrot ecrire :\n     mandelbrot\n");
	ft_putstr("\tsi vous voulez afficher mandelbrot ecrire :\n     julia\n");
}