/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 03:25:22 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/07 14:03:28 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	esc_handler(int keycode, t_fract *fract)
{
	if (keycode == 65307)
		exit_prog(fract);
	return (0);
}

void	ft_zoom(double	zoom_factor, t_fract *fract, double x, double y)
{
		fract->min_x = x + (fract->min_x - x) * zoom_factor;
		fract->max_x = x + (fract->max_x - x) * zoom_factor;
		fract->min_y = y + (fract->min_y - y)* zoom_factor;
		fract->max_y = y + (fract->max_y - y) * zoom_factor;
		if (zoom_factor < 1.0 && fract->max_iter < 200)
			fract->max_iter += 2;
		else if (fract->max_iter > 42)
			fract->max_iter -= 2;
}

int	mouse_handler(int button, int x, int y, t_fract *fract)
{
	double	zoom_factor;
	double	x_cor;
	double	y_cor;

	if (button == 4)
		zoom_factor = 0.9;
	else if (button == 5)
		zoom_factor = 1.1;
	else
		return (0);
	x_cor = fract->min_x + ((double)x / WIDTH) * (fract->max_x - fract->min_x);
	y_cor = fract->min_y + ((double)y / HEIGHT) * (fract->max_y - fract->min_y);
	ft_zoom(zoom_factor, fract, x_cor, y_cor);
	draw_fractal(fract);
	return (0);
}
