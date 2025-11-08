/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:12:49 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/07 20:08:36 by jmora-ro         ###   ########.fr       */
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
void	print_error_and_exit(void);
void	free_and_exit(int *numbers);
int		*parse_input(int argc, char **argv);
void	validate_input(int argc, char **argv);
void	check_duplicates(int *numbers, int count);
int		is_valid_range(long num);
t_stack	*stack_new(int value);
t_stack *array_to_stack(int *arr, int size);
void	stack_add_back(t_stack **stack, t_stack *node);
void 	free_stack(t_stack **stack);


#endif
