/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 01:57:17 by ccakir            #+#    #+#             */
/*   Updated: 2025/05/31 01:57:17 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *number)
{
	int	res;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	res = 0;
	while (is_space(number[i]))
		i++;
	if (number[i] == '-' || number[i] == '+')
	{
		if (number[i] == '-')
			sign = -1;
		i++;
	}
	while ((number[i] >= '0' ) && (number[i] <= '9'))
	{
		if ((res + (number[i] - 48)) > 2147483647)
			return (-1);
		res = (res * 10) + (number[i] - 48);
		i++;
	}
	return (res * sign);
}
