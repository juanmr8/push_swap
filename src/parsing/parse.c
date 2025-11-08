/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:44:28 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/06 16:44:51 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"


long ft_atol(char *str)
{
	long result;
	int sign;
	int i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	*parse_input(int argc, char **argv)
{
	int		*numbers;
	long	num;
	int		i;

	numbers = malloc(sizeof(int) * argc);
	if (!numbers)
		print_error_and_exit();
	i = 0;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
        if (!is_valid_range(num))
		{
			free(numbers);
			print_error_and_exit();
		}
		numbers[i] = num;
		i++;
	}
	return (numbers);
}
