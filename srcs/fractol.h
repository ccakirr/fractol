#ifndef FRACTOL_H
# define FRACTOL_H
# define JULIA 0
# define MANDELBROT 1

# include <stdlib.h>
# include <unistd.h>
# include "my_libs/minilibx-linux/mlx.h"
# include "my_libs/libft/libft.h"
# include "my_libs/ft_printf/ft_printf.h"

typedef struct fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_bp;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	zoom;
	double	julia_i;
	double	julia_r;
	int		type;
	int		max_iter;
}				t_fract;

char	*ft_strtolower(char *str);
double	ft_atod(char *number);
void	*julia_parameter_parser(char	**args, t_fract *fract);

#endif