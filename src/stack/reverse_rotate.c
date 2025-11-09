/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:23:07 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/09 11:03:31 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;
	t_stack *second_last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second_last = NULL;
	last = first;
	while (last->next!= NULL)
	{
		if (last->next->next == NULL)
			second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = first;
	*stack = last;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);

}
