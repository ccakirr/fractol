/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 00:15:20 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/07 16:49:33 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	pixel_to_coordinate(double value, double min, double max)
{
	double	mapped;
	double	range;

	range = max - min;
	mapped = (min + ((value / HEIGHT) * range));
	return (mapped);
}

int	calculate_julia(t_fract *fract, double zr, double zi)
{
	int		iterate;
	double	tmp;

	iterate = 0;
	while (iterate < fract->max_iter)
	{
		tmp = (zr * zr) - (zi * zi) + fract->julia_r;
		zi = (2 * zi * zr) + fract->julia_i;
		zr = tmp;
		if (zi + zr > 4)
			break ;
		iterate++;
	}
	return (iterate);
}

int	calculate_mandelbrot(t_fract *fract, double cr, double ci)
{
	double	tmp;
	double	zi;
	double	zr;
	int		iterate;

	zi = 0;
	zr = 0;
	iterate = 0;
	while (iterate < fract->max_iter)
	{
		tmp = (zr * zr) - (zi * zi) + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		if (zi * zi + zr * zr > 4.0)
			break ;
		iterate++;
	}
	return (iterate);
}

void	put_pixel(t_fract *fract, int x, int y, int iteration)
{
	char	*pixel;
	int		color;
	int		color_value;

	if (iteration == fract->max_iter)
		color = 0x000000;
	else
	{
		color_value = (iteration * 255) / fract->max_iter;
		color = (color_value << 16) | ((color_value * color_value) << 8) | (255 - color_value);

	}
	pixel = fract->img_bp + (y * fract->line_lenght
			+ x * (fract->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	draw_fractal(t_fract *fract)
{
	int		x;
	int		y;
	int		iteration;
	double	cr;
	double	ci;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		ci = pixel_to_coordinate(y, fract->min_y, fract->max_y);
		while (x < WIDTH)
		{
			cr = pixel_to_coordinate(x, fract->min_x, fract->max_x);
			if (!(fract->type))
				iteration = calculate_julia(fract, cr, ci);
			else
				iteration = calculate_mandelbrot(fract, cr, ci);
			put_pixel(fract, x, y, iteration);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
