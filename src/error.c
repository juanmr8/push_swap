/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:50:34 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/09 11:10:57 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void print_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

void print_error_and_exit(void)
{
	print_error();
	exit(1);
}

void print_specific_error(char *error_msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void error_invalid_input(void)
{
	print_specific_error("Invalid input format");
}

void error_non_numeric(void)
{
	print_specific_error("Non-numeric character found");
}

void error_duplicate(void)
{
	print_specific_error("Duplicate numbers not allowed");
}

void error_out_of_range(void)
{
	print_specific_error("Number out of integer range");
}

void error_malloc_failed(void)
{
	print_specific_error("Memory allocation failed");
}

void free_and_exit(int *arr)
{
	if (arr)
		free(arr);
	print_error_and_exit();
}
