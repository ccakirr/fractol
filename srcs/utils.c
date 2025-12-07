/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 23:22:41 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/07 13:56:55 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_strlower(char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

void	error_exit(char *msg)
{
	write(2, "Error\n", 6);
	if (!msg)
		write(2, "Unknown Error!", ft_strlen("Unknown Error!"));
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

int	exit_prog(t_fract *fract)
{
	if (fract->img)
		mlx_destroy_image(fract->mlx, fract->img);
	if (fract->win)
		mlx_destroy_window(fract->mlx, fract->win);
	if (fract->mlx)
	{
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
	}
	exit(0);
}

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
	{
		return (1);
	}
	return (0);
}