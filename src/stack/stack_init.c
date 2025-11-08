/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:44:39 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/08 12:12:52 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack *stack_new(int value)
{
	t_stack *stack;

	stack = malloc(sizeof (t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->index = 0;
	stack->next = NULL;
	return (stack);
}

int	stack_size(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_stack *stack_last(t_stack *stack)
{
	t_stack *i;

	if (!stack)
		return (NULL);
	i = stack;
	while (i->next != NULL)
		i = i->next;
	return (i);
}

void stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack *temp;

	temp = *stack;
	if (!temp)
	{
		*stack = new;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

t_stack *array_to_stack(int *arr, int size)
{
	int	i;
	t_stack	*stack;
	t_stack *node;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		node = stack_new(arr[i]);
		if (!node)
			return (NULL);
		stack_add_back(&stack, node);
		i++;
	}
	return (stack);
}
