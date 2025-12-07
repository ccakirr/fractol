/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listeners.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 03:28:16 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/07 13:37:39 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx_events(t_fract *fract)
{
	mlx_mouse_hook(fract->win, mouse_handler, fract);
	mlx_key_hook(fract->win, esc_handler, fract);
	mlx_hook(fract->win, 17, 0, exit_prog, fract);
}