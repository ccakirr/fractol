/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 05:39:30 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/06 18:31:01 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	apply_zoom(t_fract *f, int button, int x, int y)
{
	double	zoom_factor;
	double	cr;
	double	ci;

	if (button == 4)
	{
		zoom_factor = 0.9;
		f->zoom = f->zoom * 1.1;
	}
	else
	{
		zoom_factor = 1.1;
		f->zoom = f->zoom * 0.9;
	}
	cr = map(x, f->min_x, f->max_x);
	ci = map(y, f->min_y, f->max_y);
	f->min_x = cr + (f->min_x - cr) * zoom_factor;
	f->max_x = cr + (f->max_x - cr) * zoom_factor;
	f->min_y = ci + (f->min_y - ci) * zoom_factor;
	f->max_y = ci + (f->max_y - ci) * zoom_factor;
}

void	update_iterations(t_fract *f)
{
	f->max_iter = 42 + (int)(20 * f->zoom);
	if (f->max_iter > 500)
		f->max_iter = 500;
}

int	mouse_handler(int button, int x, int y, t_fract *f)
{
	if (button != 4 && button != 5)
		return (0);
	apply_zoom(f, button, x, y);
	update_iterations(f);
	draw_fractal(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

int	handle_esc(int keycode, t_fract *fract)
{
	if (keycode == 65307)
		exit_prog(fract);
	return (0);
}
