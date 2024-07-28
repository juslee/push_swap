/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:49:43 by welee             #+#    #+#             */
/*   Updated: 2024/07/27 21:55:43 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	find_min_index(t_stack *a)
{
	int		min;
	int		min_index;
	t_node	*current;
	int		i;

	current = a->top;
	min = current->value;
	min_index = 0;
	i = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}

static void	move_to_top(t_stack *a, int index)
{
	int	size;

	size = a->size;
	if (index <= size / 2)
	{
		while (index-- > 0)
			ra(a);
	}
	else
	{
		index = size - index;
		while (index-- > 0)
			rra(a);
	}
}

void	turk_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	min_index;

	size = a->size;
	while (size > 3)
	{
		min_index = find_min_index(a);
		move_to_top(a, min_index);
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
