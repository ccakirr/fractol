/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 22:57:54 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/07 13:56:30 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 800
# define HEIGHT 800
# define JULIA 0
# define MANDELBROT 1

# include <unistd.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/minilibx-linux/mlx.h"

typedef struct s_fract
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_bp;
	int		bits_per_pixel;
	int		line_lenght;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	julia_r;
	double	julia_i;
	int		max_iter;
	int		type;
	int		endian;
}				t_fract;

char	*ft_strlower(char *str);
int		type_parsing(char **av, int ac, t_fract *fract);
void	error_exit(char *msg);
void	draw_fractal(t_fract *fract);
int		exit_prog(t_fract *fract);
int		esc_handler(int keycode, t_fract *fract);
void	init_mlx_events(t_fract *fract);
double	pixel_to_coordinate(double value, double min, double max);
int		mouse_handler(int button, int x, int y, t_fract *fract);
int		is_space(char c);
#endif