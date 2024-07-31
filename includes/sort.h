/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:16:33 by welee             #+#    #+#             */
/*   Updated: 2024/07/31 17:39:35 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "stack.h"
# include "operations.h"

typedef struct s_cost
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_cost;

// Main sorting function
void	sort_stack(t_stack *a, t_stack *b);

// Helper sorting functions
void	sort_three(t_stack *a);
// void	sort_five(t_stack *a, t_stack *b);
// void	insertion_sort(t_stack *a, t_stack *b);
// void	iterative_sort(t_stack *a, t_stack *b);
// void	radix_sort(t_stack *a, t_stack *b);

// Turk Sort functions
void	turk_sort(t_stack *a, t_stack *b);
t_cost	calculate_cost(t_stack *a, t_stack *b, int index_a);
void	move_cheapest(t_stack *a, t_stack *b);
void	move_element(t_stack *a, t_stack *b, t_cost cost);
t_cost	determine_operation(t_cost cost);
void	push_back(t_stack *a, t_stack *b);
void	rotate_to_min(t_stack *a);

#endif
