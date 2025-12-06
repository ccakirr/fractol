/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:38:38 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/06 17:38:39 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define JULIA 0
# define MANDELBROT 1
# define WIDTH 800
# define HEIGHT 800

# include <stdlib.h>
# include <unistd.h>
# include "../my_libs/minilibx-linux/mlx.h"
# include "../my_libs/libft/libft.h"
# include "../my_libs/ft_printf/ft_printf.h"

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
	double	julia_i;
	double	julia_r;
	int		type;
	int		max_iter;
}				t_fract;

char	*ft_strtolower(char *str);
double	ft_atod(char *number);
int		type_parser(char **args, int ac, t_fract *fract);
void	julia_parameter_parser(char **args, t_fract *fract);
void	init_mlx(t_fract *fract);
void	draw_fractal(t_fract *fract);
void	error_exit(char *msg);
double	map(double value, double min, double max);
int		mouse_handler(int button, int x, int y, t_fract *fract);
int		handle_esc(int keycode, t_fract *fract);
int		exit_prog(t_fract *fract);
void	init_mlx_events(t_fract *fract);

#endif