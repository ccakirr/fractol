/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 03:57:00 by ccakir            #+#    #+#             */
/*   Updated: 2025/06/01 03:57:00 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void	*src, size_t	n)
{
	char	*cpy;
	char	*source;

	if (!dest && !src)
		return (NULL);
	source = (char *)src;
	cpy = (char *)dest;
	while (n--)
		*cpy++ = *source++;
	return (dest);
}
