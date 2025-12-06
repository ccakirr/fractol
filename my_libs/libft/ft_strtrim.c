/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 01:27:26 by ccakir            #+#    #+#             */
/*   Updated: 2025/06/08 01:27:26 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inset(char const	c, char const	*set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const	*str, char const	*set)
{
	int		start;
	int		end;
	char	*res;

	if (!str || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(str) - 1;
	while (str[start] && (is_inset(str[start], set)))
		start++;
	while ((str[end]) && (is_inset(str[end], set)))
		end--;
	res = ft_substr(str, start, (end - start + 1));
	return (res);
}
