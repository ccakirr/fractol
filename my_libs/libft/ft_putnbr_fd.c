/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:43:33 by ccakir            #+#    #+#             */
/*   Updated: 2025/06/05 15:43:33 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	c;

	nbr = n;
	if (n < 0)
	{
		write (fd, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr >= 10)
		ft_putnbr_fd (nbr / 10, fd);
	c = (nbr % 10) + '0';
	write (fd, &c, 1);
}
