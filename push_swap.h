/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:12:49 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/11 11:26:40 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "lib/libft/libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
    int              value;
    int              index;
    struct s_stack   *next;
}   t_stack;

long	ft_atol(char *str);
void	print_error(void);
void	print_error_and_exit(void);
void	print_specific_error(char *error_msg);
void	error_invalid_input(void);
void	error_non_numeric(void);
void	error_duplicate(void);
void	error_out_of_range(void);
void	error_malloc_failed(void);
void	free_and_exit(int *numbers);
int		*parse_input(int argc, char **argv);
void	validate_input(int argc, char **argv);
void	check_duplicates(int *numbers, int count);
int		is_valid_range(long num);
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stack);
t_stack	*array_to_stack(int *arr, int size);
void	stack_add_back(t_stack **stack, t_stack *node);
void 	free_stack(t_stack **stack);
int		is_sorted(t_stack *stack);
int		stack_size(t_stack *lst);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		get_position(t_stack *stack, int value);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
int		stack_size(t_stack *stack);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	push_min_to_b(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	assign_indices(t_stack **stack_a);
int		has_elements_in_range(t_stack *stack, int min, int max);
int		calculate_chunk_count(int stack_size);
int		find_closest_in_range(t_stack *stack, int min, int max, int size);
void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b);
int		is_in_range(t_stack *stack, int min, int max);
int		should_rotate_up(int position, int stack_size);
int		find_max_index(t_stack *stack);
int		get_position_by_index(t_stack *stack, int target_index);
void	push_back_to_a(t_stack **stack_a, t_stack **stack_b);
void	sort_large(t_stack **stack_a, t_stack **stack_b);
#endif
