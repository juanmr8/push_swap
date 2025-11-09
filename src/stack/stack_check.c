/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:32:12 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/09 11:32:30 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int is_sorted(t_stack *stack)
{
	if (!stack || !stack->next)
		return(1);
	while(stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int get_min(t_stack *stack)
{
	int min;

	if (!stack)
		return (0);
	min = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (min > stack->value)
			min = stack->value;
		stack = stack->next;
	}
	return min;
}

int get_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (max < stack->value)
			max = stack->value;
		stack = stack->next;
	}
	return max;
}

int get_position(t_stack *stack, int value)
{
	int	position;

	position = 0;
	if (!stack)
		return (-1);
	while (stack)
	{
		if (stack->value == value)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}
