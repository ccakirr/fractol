/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:51:12 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/06 03:32:37 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_strtolower(char *str)
{
	int	i;

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