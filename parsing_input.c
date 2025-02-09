/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 17:15:08 by cgil              #+#    #+#             */
/*   Updated: 2025-02-06 17:15:08 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static const char	*is_valid_input(const char *str);

void	parse_input(t_data *data, char *av[])
{
	data->n_philos = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]) * 1e3;
	data->time_to_eat = ft_atol(av[3]) * 1e3;
	data->time_to_sleep = ft_atol(av[4]) * 1e3;
	if (data->time_to_die < 6e4
		|| data->time_to_die < 6e4 || data->time_to_die < 6e4)
		print_err("The timestamps must be major than 60ms");
	if (av[5])
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -1;
}

static	int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
	{
		return (1);
	}
	return (0);
}

static long	ft_atol(const char *input)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	input = is_valid_input(input);
	while (ft_isdigit(input[i]))
		num = (num * 10) + (input[i++] - '0');
	if (num > INT_MAX)
		print_err("The value is too big");
	return (num);

}

static const char	*is_valid_input(const char *str)
{
	int	i;
	const char *num;

	num = 0;
	i = 0;

	while (*str== ' ' || (*str >= 9 && *str <= 13))
		*str++;
	if (*str == '+')
		*str++;
	else if (*str == '-')
		print_err("The program does not accept negative values\n");
	if (!ft_isdigit(*str))
			print_err("Invalid input: input is not a number");
	num = str;
	while (ft_isdigit(*str))
		*str++;
	if (*str != *str== ' ' || (*str >= 9 && *str <= 13))
		print_err("Invalid input: input is not a number");
	if (i > 10)
		print_err("The value is too big");
	return (num);
}
