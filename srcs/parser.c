/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 22:57:38 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/07 13:55:03 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_valid_number(char *str)
{
	int	i;
	int	has_digit;
	int	has_dot;

	i = 0;
	has_digit = 0;
	has_dot = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			has_digit = 1;
		else if (str[i] == '.' && !has_dot)
			has_dot = 1;
		else
			return (0);
		i++;
	}
	return (has_digit);
}

static int	parse_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (is_space(str[*i]))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static double	parse_fraction(char *str, int *i)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 1.0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			fraction = fraction * 10.0 + (str[*i] - '0');
			divisor *= 10.0;
			(*i)++;
		}
	}
	return (fraction / divisor);
}

double	ft_atod(char *number)
{
	double	res;
	int		sign;
	int		i;

	i = 0;
	res = 0.0;
	sign = parse_sign(number, &i);
	while (number[i] >= '0' && number[i] <= '9')
	{
		res = res * 10.0 + (number[i] - '0');
		i++;
	}
	res += parse_fraction(number, &i);
	return (res * sign);
}

int	type_parsing(char	**av, int ac, t_fract *fract)
{
	char	*type;

	if (ac < 2)
		ft_printf("Please enter valid args.");
	type = ft_strlower(av[1]);
	if (ft_strncmp("mandelbrot", type, 10) == 0
		&& ft_strlen(type) == 10 && ac == 2)
		return (fract->type = MANDELBROT, 0);
	else if (ft_strncmp("julia", type, 5) == 0 && ac == 4)
	{
		if (!is_valid_number(av[2]) || !is_valid_number(av[3]))
		{
			ft_printf("Julia parameters must be numeric values.\n");
			return (1);
		}
		fract->julia_r = ft_atod(av[2]);
		fract->julia_i = ft_atod(av[3]);
		fract->type = JULIA;
		return (0);
	}
	else
		ft_printf("Please enter valid args.");
	return (1);
}
