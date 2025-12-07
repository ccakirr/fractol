/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:36:08 by ccakir            #+#    #+#             */
/*   Updated: 2025/06/08 00:36:08 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*res;
	int		lenone;
	int		lentwo;

	lenone = ft_strlen(s1);
	lentwo = ft_strlen(s2);
	res = malloc(sizeof(char) * (lenone + lentwo + 1));
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		res[i] = s1[i];
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}
