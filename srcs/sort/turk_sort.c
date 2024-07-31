/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:49:43 by welee             #+#    #+#             */
/*   Updated: 2024/07/31 17:39:13 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "parser.h"
#include <stdio.h>
#include <limits.h>

static int	total_cost(t_cost cost)
{
	return (ft_min(
			ft_min(ft_max(cost.ra, cost.rb), ft_max(cost.rra, cost.rrb)),
			ft_min(cost.ra + cost.rrb, cost.rra + cost.rb)));
}

void	move_cheapest(t_stack *a, t_stack *b)
{
	t_cost	min_cost;
	t_cost	current_cost;
	int		index;
	t_node	*current;

	if (a->size == 0)
		return ;
	current = a->top;
	min_cost = calculate_cost(a, b, 0);
	index = 1;
	current = current->next;
	while (current != a->top)
	{
		current_cost = calculate_cost(a, b, index);
		if (total_cost(current_cost) < total_cost(min_cost))
		{
			min_cost = current_cost;
		}
		current = current->next;
		index++;
	}
	move_element(a, b, min_cost);
}

void	turk_sort(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	while (a->size > 3)
		move_cheapest(a, b);
	sort_three(a);
	push_back(a, b);
	rotate_to_min(a);
}
