/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:03:58 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/11 10:51:29 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// Primer paso para el algo grande. Asignamos un indice unico a cada elemento en stack A basandose en su value numerico
void	assign_indices(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*compare;
	int		count;

	if (!stack_a || !*stack_a)
		return ;

	current = *stack_a;
	while (current)
	{
		count = 0;
		compare = *stack_a;
		while (compare)
		{
			if (compare->value < current->value)
				count++;
			compare = compare->next;
		}
		current->index = count;
		current = current->next;
	}
}


// In stack_check.c or sort_utils.c
int	find_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	get_position_by_index(t_stack *stack, int target_index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target_index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

int	should_rotate_up(int position, int stack_size)
{
	return (position <= stack_size / 2);
}

