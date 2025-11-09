/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:27:55 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/09 11:30:31 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_split_args(char **args)
{
	int i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

static int *init_numbers(int argc, char **argv, int *count)
{
	int *numbers;
	char **args;

	// Step 1: Handle single string input - split if necessary
	args = NULL;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*count = 0;
		while (args[*count])
			(*count)++;

		// Step 2: Validate all inputs have proper format
		validate_input(*count, args);

		// Step 3: Parse strings to integers
		numbers = parse_input(*count, args);

		// Step 4: Check for duplicates
		check_duplicates(numbers, *count);

		// Step 5: Free split array
		free_split_args(args);
	}
	else
	{
		*count = argc - 1;

		// Step 2: Validate all inputs have proper format (skip program name)
		validate_input(*count, &argv[1]);

		// Step 3: Parse strings to integers (skip program name)
		numbers = parse_input(*count, &argv[1]);

		// Step 4: Check for duplicates
		check_duplicates(numbers, *count);
	}

	if (!numbers)
		return (NULL);

	return (numbers);
}

static t_stack *init_stack(int *numbers, int count)
{
	t_stack *stack;

	stack = array_to_stack(numbers, count);
	if (!stack)
	{
		free(numbers);
		error_malloc_failed();
	}
	return (stack);
}

static void	push_swap(t_stack **stack_a)
{
	// int size;

	if (is_sorted(*stack_a))
	{
		write(1, "Stack sorted", 12);
		return ;
	}
	/** Remaining logic  */

}

int main(int argc, char **argv)
{
    int *numbers;
    int count;
	t_stack *stack_a;

    if (argc < 2)
        return (0);
    numbers = init_numbers(argc, argv, &count);
	stack_a = init_stack(numbers, count);
    free(numbers);
	push_swap(&stack_a);
	free_stack(&stack_a);
    return (0);
}
