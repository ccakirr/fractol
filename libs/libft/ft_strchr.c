/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 02:19:26 by ccakir            #+#    #+#             */
/*   Updated: 2025/05/31 02:19:26 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	s_len;

	i = 0;
	s_len = ft_strlen(s);
	while (i <= s_len)
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	return (NULL);
}
