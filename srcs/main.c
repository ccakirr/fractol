/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 22:50:20 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/07 12:40:48 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_julia(t_fract *fract)
{
	fract->min_x = -2.0;
	fract->max_x = 2.0;
	fract->min_y = -2.0;
	fract->max_y = 2.0;
	fract->max_iter = 42;
}

void	set_mandelbrot(t_fract *fract)
{
	fract->min_x = -2.0;
	fract->max_x = 1.0;
	fract->min_y = -1.5;
	fract->max_y = 1.5;
	fract->max_iter = 42;
}

void	init_minilibx(t_fract *fract)
{
	fract->mlx = mlx_init();
	if (!(fract->mlx))
		error_exit("Mlx initilation error!");
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, "fractol");
	if (!(fract->win))
		error_exit("Window creation error!");
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (!(fract->img))
		error_exit("Image creation error!");
	fract->img_bp = mlx_get_data_addr(fract->img, &fract->bits_per_pixel,
			&fract->line_lenght, &fract->endian);
}

int	main(int ac, char **av)
{
	t_fract	fract;

	if (type_parsing(av, ac, &fract))
	{
		ft_printf("The available parameters are:\n./fractol mandelbrot\n./fractol julia 'arg1' 'arg2'\n");
		exit(1);
	}
	if (!(fract.type))
		set_julia(&fract);
	if ((fract.type))
		set_mandelbrot(&fract);
	init_minilibx(&fract);
	draw_fractal(&fract);
	init_mlx_events(&fract);
	mlx_loop(fract.mlx);
	return (0);
}
