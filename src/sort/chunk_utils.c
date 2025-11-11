/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:24:31 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/11 11:32:24 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	has_elements_in_range(t_stack *stack, int min, int max)
{
	while (stack)
	{
		if (is_in_range(stack, min, max))
			return (1);  // Found at least one!
		stack = stack->next;
	}
	return (0);  // None found
}

// Si el q esta arriba de la lista esta entre los min y max del current chunk
int	is_in_range(t_stack *stack, int min, int max)
{
	return (stack->index >= min && stack->index <= max);
}

// Hecho a mano - Determinar el tamaño de cada chunk
int		calculate_chunk_count(int	stack_size)
{
	if (stack_size <= 100)
		return (4);
	else if (stack_size <= 500)
		return (11);
	else
		return (stack_size / 50);
}

// Retornamos la distancia mas cercana al siguiente indice que este dentro de nuestro chunk
int	find_closest_in_range(t_stack *stack, int min, int max, int size)
{
	int		position;
	int		closest_pos;
	int		min_distance;
	int		distance;

	position = 0;
	closest_pos = -1;
	min_distance = size + 1;
	while (stack)
	{
		if (is_in_range(stack, min, max))
		{
			if (position <= size / 2) // Si esta en la mitad alta
				distance = position; // Usamos el indice de la posicion como distancia
			else // Si no, usamos el tamaño total del stack menos la posicion
				distance = size - position;
			if (distance < min_distance)
			{
				min_distance = distance;
				closest_pos = position;
			}
		}
		position++;
		stack = stack->next;
	}
	return (closest_pos);
}
