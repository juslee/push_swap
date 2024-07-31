/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:30:39 by welee             #+#    #+#             */
/*   Updated: 2024/07/31 10:31:11 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	find_best_position(t_stack *a, int value)
{
	t_node	*current;
	int		best_pos;
	int		closest_diff;
	int		current_pos;
	int		diff;

	current = a->top;
	best_pos = 0;
	closest_diff = INT_MAX;
	current_pos = 0;
	while (current != NULL)
	{
		diff = current->value - value;
		if (diff > 0 && diff < closest_diff)
		{
			closest_diff = diff;
			best_pos = current_pos;
		}
		current = current->next;
		current_pos++;
		if (current == a->top)
			break ;
	}
	return (best_pos);
}

void	push_back(t_stack *a, t_stack *b)
{
	int	pos;
	int	cost_ra;
	int	cost_rra;

	while (b->size > 0)
	{
		pos = find_best_position(a, b->top->value);
		cost_ra = pos;
		cost_rra = a->size - pos;
		if (cost_ra <= cost_rra)
		{
			while (cost_ra-- > 0)
				ra(a);
		}
		else
		{
			while (cost_rra-- > 0)
				rra(a);
		}
		pa(a, b);
	}
}
