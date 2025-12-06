/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 05:39:30 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/06 17:45:03 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_handler(int button, int x, int y, t_fract *fract)
{
	double	zoom_factor;
	double	cr;
	double	ci;

	if (button != 4 && button != 5)
		return (0);
	if (button == 4)
	{
		zoom_factor = 0.9;
		fract->zoom *= 1.1;
	}
	else
	{
		zoom_factor = 1.1;
		fract->zoom *= 0.9;
	}
	cr = map(x, fract->min_x, fract->max_x);
	ci = map(y, fract->min_y, fract->max_y);
	fract->min_x = cr + (fract->min_x - cr) * zoom_factor;
	fract->max_x = cr + (fract->max_x - cr) * zoom_factor;
	fract->min_y = ci + (fract->min_y - ci) * zoom_factor;
	fract->max_y = ci + (fract->max_y - ci) * zoom_factor;
	fract->max_iter = 42 + (int)(20 * fract->zoom);
	if (fract->max_iter > 500)
		fract->max_iter = 500;
	draw_fractal(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
	return (0);
}

int	handle_esc(int keycode, t_fract *fract)
{
	if (keycode == 65307)
		exit_prog(fract);
	return (0);
}
