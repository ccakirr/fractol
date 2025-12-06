/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:56:28 by ccakir            #+#    #+#             */
/*   Updated: 2025/06/03 13:56:28 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptr;
	char	*ptr2;

	if (!dest && !src)
		return (NULL);
	i = 0;
	ptr = (char *) dest;
	ptr2 = (char *) src;
	if (dest > src)
	{
		i = n;
		while (i-- > 0)
			ptr[i] = ptr2[i];
	}
	while (i < n)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (dest);
}
