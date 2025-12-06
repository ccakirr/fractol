/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 20:29:39 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/06 18:09:03 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fract *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		error_exit("MLX init failed");
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, "fractol");
	if (!fract->win)
		error_exit("Window creation failed");
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (!fract->img)
		error_exit("Image creation failed");
	fract->img_bp = mlx_get_data_addr(
			fract->img,
			&fract->bits_per_pixel,
			&fract->line_length,
			&fract->endian);
}

void	julia_setup(t_fract *fract)
{
	fract->min_x = -2.0;
	fract->max_x = 2.0;
	fract->min_y = -2.0;
	fract->max_y = 2.0;
	fract->zoom = 1.0;
	fract->max_iter = 42;
}

void	mandelbrot_setup(t_fract *fract)
{
	fract->min_x = -2.0;
	fract->max_x = 1.0;
	fract->min_y = -1.5;
	fract->max_y = 1.5;
	fract->zoom = 1.0;
	fract->max_iter = 42;
}

int	main(int ac, char **av)
{
	t_fract	fract;
	int		type;

	if (ac < 2)
		error_exit("Please enter the fractal type!");
	type = type_parser(av, ac, &fract);
	if (type == 0)
	{
		ft_printf("Parsing error\n");
		return (1);
	}
	else if (fract.type)
		mandelbrot_setup(&fract);
	else if (!(fract.type))
	{
		julia_parameter_parser(av, &fract);
		julia_setup(&fract);
	}
	init_mlx(&fract);
	draw_fractal(&fract);
	init_mlx_events(&fract);
	return (0);
}
