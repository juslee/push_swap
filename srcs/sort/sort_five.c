/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:51:18 by welee             #+#    #+#             */
/*   Updated: 2024/07/28 15:57:27 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <stdio.h>

static int	find_min_index(t_stack *a)
{
	t_node	*current;
	int		min;
	int		min_index;
	int		i;

	if (!a || !a->top)
		return (-1);
	current = a->top;
	min = current->value;
	min_index = 0;
	i = 0;
	while (i < a->size)
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

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = find_min_index(a);
	move_to_top(a, min_index);
	pb(a, b);
	min_index = find_min_index(a);
	move_to_top(a, min_index);
	pb(a, b);
	sort_three(a);
	if (b->top->value < b->top->next->value)
		sb(b);
	pa(a, b);
	pa(a, b);
}
