/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:11:30 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/17 21:30:47 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	only_digit(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[0] == '\0')
	{
		print_error("Argument is empty or NULL.\n");
		return (false);
	}
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			print_error("Argument is non-digit characters.\n");
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	is_overflow(const char *str, int *result)
{
	long long	nb;

	nb = 0;
	while (*str != '\0')
	{
		nb = nb * 10 + (*str - '0');
		if (nb > INT_MAX)
		{
			print_error("Value is over INT_MAX.\n");
			return (false);
		}
		str++;
	}
	*result = nb;
	return (true);
}

static bool	check_argv_value(int argc, int result)
{
	if (argc == 1 && !(0 < result && result <= 250))
	{
		print_error("Number of philo is out of range (1 to 250).\n");
		return (false);
	}
	else if ((2 <= argc && argc <= 5) && result < 1)
	{
		print_error("Argument is wrong.\n");
		return (false);
	}
	return (true);
}

bool	check_correct_args(int argc, char **argv)
{
	int	i;
	int	argv_value;

	if (argc < 5 || 6 < argc)
	{
		print_error("Argc is wrong.\n");
		return (false);
	}
	i = 1;
	while (i < argc)
	{
		if (!only_digit(argv[i]))
			return (false);
		if (!is_overflow(argv[i], &argv_value))
			return (false);
		if (!check_argv_value(i, argv_value))
			return (false);
		i++;
	}
	return (true);
}
