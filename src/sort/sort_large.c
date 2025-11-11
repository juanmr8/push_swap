/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:29:40 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/11 11:26:52 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	process_chunk_element(t_stack **stack_a, t_stack **stack_b, int chunk_min, int chunk_max, int size)
{
	int	chunk_mid;

	if (is_in_range(*stack_a, chunk_min, chunk_max))
	{
		pb(stack_a, stack_b); // Si esta en el current chunk chunk lo paso a B.
		chunk_mid = (chunk_min + chunk_max) / 2;
		if ((*stack_b)->index < chunk_mid)
			rb(stack_b); // Aprovecho para meter una rotacion en B desp del push con ese nuevo elemento
	}
	else { // Si no esta en mi chunk, busco el siguiente nodo que si lo este (primero veo si esta por la mitad de arriba o abajo)
		int pos = find_closest_in_range(*stack_a, chunk_min, chunk_max, size);
		if (pos <= size / 2) // Si esta en la mitad alta (entre el 50% de los primeros numeros)
		{
			// Rotar hasta que consigamos q el que esta en este chunk este arriba
			while (!is_in_range(*stack_a, chunk_min, chunk_max))
				ra(stack_a);
		}
		else
		{
			// Rotar desde abajo hasta que este arriba el que tiene un indice que pertenezca a este chunk
			while (!is_in_range(*stack_a, chunk_min, chunk_max))
				rra(stack_a);
		}
	}
}

void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk_count;
	int	size;
	int	i;
	int	chunk_min;
	int	chunk_max;

	size = stack_size(*stack_a);
	chunk_count = calculate_chunk_count(size);
	i = 0; // Representa el numero de chunk de 0 a chunk_count - 1
	while (i < chunk_count) // Por cada chunk que tenga voy a ir calculando min y max y despues ver si tiene elementos cuyo indice pertenzca a ese chunk
	{
		/* Ejemplo:
		*	i = 0
		*  	chunk_min = (100 * 0) / 5 = 0 / 5 = 0
  		*	chunk_max = (100 * 1) / 5 - 1 = 20 - 1 = 19
		* - ---- - -- - -
		*   i = 2;
		* 	chunk_min = (100 * 2) / 5 = 200 / 5 = 40
  		*	chunk_max = (100 * 3) / 5 - 1 = 60 - 1 = 59
		**/
		chunk_min = (size * i) / chunk_count;
		chunk_max = (size * (i + 1)) / chunk_count - 1;
		while (has_elements_in_range(*stack_a, chunk_min, chunk_max))
			process_chunk_element(stack_a, stack_b, chunk_min, chunk_max, size);
		i++; // Pasamos al siguiente chunk
	}
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max_index;
	int	max_pos;
	int	size;

	size = stack_size(*stack_b);
	while (*stack_b)
	{
		max_index = find_max_index(*stack_b);
		max_pos = get_position_by_index(*stack_b, max_index);
		if (max_pos <= size / 2)
		{
			while ((*stack_b)->index != max_index)
				rb(stack_b);
		}
		else
		{
			while ((*stack_b)->index != max_index)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		size--;
	}
}

void	sort_large(t_stack **stack_a, t_stack **stack_b)
{
	assign_indices(stack_a);
	push_chunks_to_b(stack_a, stack_b);
	push_back_to_a(stack_a, stack_b);
}
