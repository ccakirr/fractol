/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 03:07:46 by ccakir            #+#    #+#             */
/*   Updated: 2025/06/01 03:07:46 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
