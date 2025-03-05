/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:15:08 by cgil              #+#    #+#             */
/*   Updated: 2025/02/18 18:07:37 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static const char	*is_valid_input(const char *str);
static int			ft_isdigit(int n);

static long	ft_atol(const char *input)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	input = is_valid_input(input);
	if (!input)
		return (-2);
	while (ft_isdigit(input[i]))
		num = (num * 10) + (input[i++] - '0');
	if (num > INT_MAX)
	{
		printf("The value is bigger than INT_MAX");
		return (-2);
	}
	return (num);
}

int	parse_input(t_data *data, char *av[])
{
	data->n_philos = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	if (data->n_philos == -2 || data->time_to_die == -2
		|| data->time_to_eat == -2 || data->time_to_sleep == -2)
		return (-2);
	data->time_to_die *= 1000;
	data->time_to_eat *= 1000;
	data->time_to_sleep *= 1000;
	if (data->time_to_die < 60000
		|| data->time_to_sleep < 60000 || data->time_to_eat < 60000)
	{
		printf("The timestamps must be major than 60ms");
		return (-2);
	}
	if (av[5])
		data->must_eat = ft_atol(av[5]);
	else
		data->must_eat = -1;
	return (0);
}

static	int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
	{
		return (1);
	}
	return (0);
}

static const char	*is_valid_input(const char *str)
{
	int	i;

	i = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		printf("The program does not accept negative values\n");
		return (NULL);
	}
	if (!ft_isdigit(*str))
	{
		printf("The input has non numeric characters\n");
		return (NULL);
	}
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
	{
		printf("The input has non numeric characters\n");
		return (NULL);
	}
	return (str);
}
