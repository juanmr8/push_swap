/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:43:27 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/11 10:38:59 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three(t_stack **a)
{
	int	max;

	max = get_max(*a);
	if ((*a)->value == max)
	{
		ra(a);
		if (!is_sorted(*a))
			sa(a);
	}
	else if ((*a)->next->value == max)
	{
		rra(a);
		if (!is_sorted(*a))
			sa(a);
	}
	else
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
}

void	push_min_to_b(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;
	int	size;

	min = get_min(*a);
	pos = get_position(*a, min);
	size = stack_size(*a);
	if (pos <= (size / 2)) // Min is in top half → rotate forward
	{
		while ((*a)->value != min)
			ra(a);
	}
	else // Min esta en el 50% inferior -> rotamos desde abajo
	{
		while ((*a)->value != min)
			rra(a);
	}
	// Now min is at top, push it to B
	pb(a, b);
}

void sort_five(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 5)
	{
		push_min_to_b(a, b);
		push_min_to_b(a, b);
		// Now A has 3 elements, B has 2 (smallest on top)
	}
	else if (size == 4)
	{
		push_min_to_b(a, b);
		// Now A has 3 elements, B has 1
	}
	sort_three(a);
	while ((*b))
		pa(a, b);
}

