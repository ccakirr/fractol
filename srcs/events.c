/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:34:27 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/06 17:39:03 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx_events(t_fract *fract)
{
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
	mlx_mouse_hook(fract->win, mouse_handler, fract);
	mlx_key_hook(fract->win, handle_esc, fract);
	mlx_hook(fract->win, 17, 0, exit_prog, fract);
	mlx_loop(fract->mlx);
}
