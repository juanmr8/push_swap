/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:04:38 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/06 15:07:22 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void *safe_malloc(size_t size)
{
    void *ptr;

    ptr = malloc(size);
    if (!ptr)
		print_error_and_exit();
    return (ptr);
}

void free_stack(t_stack **stack)
{
    t_stack *current;
    t_stack *next;

    if (!stack || !*stack)
        return;
    current = *stack;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}
