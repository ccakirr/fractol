/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 03:01:40 by ccakir            #+#    #+#             */
/*   Updated: 2025/05/31 03:01:40 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_len;

	s_len = ft_strlen(s);
	while (0 <= s_len)
	{
		if (s[s_len] == (char)c)
		{
			return ((char *)(s + s_len));
		}
		s_len--;
	}
	return (NULL);
}
