/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:49:46 by ccakir            #+#    #+#             */
/*   Updated: 2025/06/09 18:49:46 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countfounder(int n)
{
	int		i;
	long	ncp;

	i = 0;
	ncp = n;
	if (n == 0)
		return (1);
	if (ncp < 0)
		i++;
	while (ncp)
	{
		ncp = ncp / 10;
		i++;
	}
	return (i);
}

static char	*itszero(char	*res)
{
	res[0] = 48;
	res[1] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	ncp;

	ncp = n;
	len = countfounder(ncp);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (ncp < 0)
	{
		res[0] = '-';
		ncp *= -1;
	}
	if (ncp == 0)
		return (itszero(res));
	res[len] = '\0';
	while (--len >= 0 && res[len] != '-')
	{
		res[len] = (ncp % 10) + '0';
		ncp = ncp / 10;
	}
	return (res);
}
