/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 20:29:39 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/06 02:44:04 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_mlx(t_fract *fract)
{
	fract->mlx = mlx_init();
	if (!(fract->mlx))
	{
		ft_printf("MLX initilation error!");
		exit(1);
	}
	fract->win = mlx_new_window(fract->mlx, 800, 800, "fractol");
	if (!(fract->win))
	{
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		exit(1);
	}
	fract->img = mlx_new_image(fract->mlx, 800, 800);
	if (!(fract->img))
	{
		mlx_destroy_display(fract->mlx);
		mlx_destroy_window(fract->mlx, fract->win);
		free(fract->mlx);
		exit(1);
	}
	fract->img_bp = mlx_get_data_addr(fract->img, &fract->bits_per_pixel,
        &fract->line_length,
        &fract->endian
    );
}
void	julia_setup(t_fract *fract)
{
	fract->min_x = -2.0;
	fract->max_x = 2.0;
	fract->min_y = -2.0;
	fract->max_y = 2.0;
	fract->max_iter = 50;
}
void	mandelbrot_setup(t_fract *fract)
{
	fract->min_x = -2.0;
	fract->max_x = 1.0;
	fract->min_y = -1.5;
	fract->max_y = 1.5;
	fract->max_iter = 50;
}

int	main(int ac, char **av)
{
	int		*julia_parameters;
	t_fract	fract;
	int		type;

	type = type_parser(av, ac, &fract);
	if (type == 0)
	{
		ft_printf("Parsing error\n");
		return (1);
	}
	else if (fract.type)
	{
		mandelbrot_setup(&fract);
	}	
	else if(!(fract.type))
	{
		julia_parameter_parser(av, &fract);
		julia_setup(&fract);
	}
	set_mlx(&fract);
}
