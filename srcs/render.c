/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 02:27:17 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/06 03:35:32 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double map(double value, double min, double max)
{
	double	mapped;
	double	range;
	
	range = max - min;
	mapped = min + ((value / 800) * range);
	return (mapped);
}

int	mandelbrot(double cr, double ci, int max_iter)
{
	int		i;
	double	zi;
	double	zr;
	double	tmp;
	
	zi = 0;
	zr = 0;
	i = 0;
	while(i < max_iter)
	{
		tmp = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zr * zi) + ci;
		zr = tmp;
		if((zr * zr) + (zi * zi) > 4)
			break ;
		i++;
	}
	return (i);
}

int	julia(double zr, double zi, double jr, double ji, int max_iter)
{
	int		i;
	double tmp;
	
	i = 0;
	while(i < max_iter)
	{
		tmp = (zr * zr) - (zi * zi) + jr;
		zi = (2 * zr * zi) + ji;
		zr = tmp;
		if((zr * zr) + (zi * zi) > 4)
			break ;
		i++;
	}
	return (i);
}

void	put_pixel(t_fract *fract, int x, int y, unsigned int color)
{
    char *pixel;

    pixel = fract->img_bp + (y * fract->line_length + x * (fract->bits_per_pixel / 8));
    *(unsigned int *)pixel = color;
}

void	draw_fractal(t_fract *fract)
{
	int		y;
	int		x;
	int		iter;
	int		color;
	double	cr;
	double	ci;

	y = 0;
	while(y < 800)
	{
		x = 0;
		ci = map(y, fract->min_y, fract->max_y);
		while(x < 800)
		{
			cr = map(x, fract->min_x, fract->max_x);
			if(fract->type == JULIA)
				iter = julia(cr, ci, fract->julia_r, fract->julia_i, fract->max_iter);
			else
				iter = mandelbrot(cr, ci, fract->max_iter);
			color = (iter * 255 / fract->max_iter) << 16;
			put_pixel(fract, x, y, color);
			x++;
		}
		y++;
	}
}
