/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:48:32 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/06 18:33:02 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
	{
		return (1);
	}
	return (0);
}

double	ft_atod(char *number)
{
	double	res;
	double	sign;
	double	fraction;
	double	divisor;
	int		i;

	i = 0;
	res = 0.0;
	fraction = 0.0;
	divisor = 1.0;
	sign = 1.0;
	while (is_space(number[i]))
		i++;
	if (number[i] == '-' || number[i] == '+')
	{
		if (number[i] == '-')
			sign = -1.0;
		i++;
	}
	while (number[i] >= '0' && number[i] <= '9')
	{
		res = res * 10.0 + (number[i] - '0');
		i++;
	}
	if (number[i] == '.')
	{
		i++;
		while (number[i] >= '0' && number[i] <= '9')
		{
			fraction = fraction * 10.0 + (number[i] - '0');
			divisor *= 10.0;
			i++;
		}
	}
	return ((res + (fraction / divisor)) * sign);
}

int	type_parser(char **args, int ac, t_fract *fract)
{
	char	*type;

	if (ac < 2)
		return (ft_printf("Error: Missing argument.\n"), 0);
	type = ft_strtolower(args[1]);
	if (!ft_strncmp(type, "julia", 5))
	{
		if (ac != 4)
			return (ft_printf("Error: Julia needs 2 params.\n"), 0);
		fract->type = JULIA;
		return (1);
	}
	if (!ft_strncmp(type, "mandelbrot", 10))
	{
		if (ac != 2)
			return (ft_printf("Error: Mandelbrot takes no params.\n"), 0);
		fract->type = MANDELBROT;
		return (1);
	}
	ft_printf("Error: Invalid type. Use julia or mandelbrot.\n");
	return (0);
}

void	julia_parameter_parser(char	**args, t_fract *fract)
{
	fract->julia_i = ft_atod(args[2]);
	fract->julia_r = ft_atod(args[3]);
}
