/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:45:45 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/06 16:24:04 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
* Input are numbers
* If numbers are inside a string
*/

void	validate_input(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (argv[i][j] == '\0')
			print_error_and_exit();
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				print_error_and_exit();
			j++;
		}
		ft_putstr_fd(argv[i], 1);
		write(1, "\n", 1);
		i++;
	}
}

void check_duplicates(int *numbers, int count)
{
	int i;
	int j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
			{
				free(numbers);
				print_error_and_exit();
			}
			j++;
		}
		i++;
	}
}

int is_valid_range(long num)
{
    if (num > 2147483647 || num < -2147483648)
        return (0);
    return (1);
}
