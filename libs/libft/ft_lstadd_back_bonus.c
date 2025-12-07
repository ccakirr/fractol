/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/06/12 15:11:27 by ccakir            #+#    #+#             */
/*   Updated: 2025/06/12 15:11:27 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	int		last;
	t_list	*tmp;
	int		i;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	last = ft_lstsize(*alst);
	i = 0;
	tmp = *alst;
	while (++i < last)
		tmp = tmp->next;
	tmp->next = new;
}
