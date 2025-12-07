/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 03:25:47 by ccakir            #+#    #+#             */
/*   Updated: 2025/05/31 03:25:47 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	size_t	big_len;

	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i + little_len <= len && i + little_len <= big_len)
	{
		if (!(ft_strncmp(&big[i], little, little_len)))
		{
			return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
