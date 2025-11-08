/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:50:34 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/06 15:06:58 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void print_error(void)
{
    write(2, "Error\n", 6);
}

void print_error_and_exit(void)
{
    print_error();
    exit(1);
}

void free_and_exit(int *arr)
{
	if (arr)
		free(arr);
	print_error_and_exit();
}
