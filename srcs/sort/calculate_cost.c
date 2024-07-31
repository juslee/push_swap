/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:14:21 by welee             #+#    #+#             */
/*   Updated: 2024/07/31 18:16:00 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "libft.h"

static int	find_max(t_stack *b)
{
	t_node	*current;
	int		max;

	if (b->top == NULL)
		return (0);
	current = b->top;
	max = current->value;
	current = current->next;
	while (current != b->top)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

static int	find_max_value_index(t_stack *b, int max_value)
{
	t_node	*current;
	int		index;

	current = b->top;
	index = 0;
	while (current->value != max_value)
	{
		current = current->next;
		index++;
	}
	return (index);
}

static int	find_best_fit_index(t_stack *b, int value)
{
	t_node	*current;
	t_node	*best_fit;
	int		index;
	int		best_fit_index;

	current = b->top;
	index = 0;
	best_fit = NULL;
	best_fit_index = -1;
	while (index < b->size)
	{
		if ((current->value <= value) &&
			(best_fit == NULL || current->value > best_fit->value))
		{
			best_fit = current;
			best_fit_index = index;
		}
		current = current->next;
		index++;
	}
	return (best_fit_index);
}

static int	find_target_index_b(t_stack *b, int value)
{
	int	max_value;
	int	best_fit_index;

	if (!b->top)
		return (0);
	max_value = find_max(b);
	best_fit_index = find_best_fit_index(b, value);
	if (best_fit_index == -1 || value > max_value)
		best_fit_index = find_max_value_index(b, max_value);
	return (best_fit_index);
}

#include <stdio.h>

t_cost	calculate_cost(t_stack *a, t_stack *b, int index_a)
{
	t_cost	cost;
	t_node	*current;
	int		target_index_b;
	int		i;

	current = a->top;
	i = 0;
	while (i < index_a)
	{
		current = current->next;
		i++;
	}
	cost.ra = index_a;
	cost.rra = a->size - index_a;
	target_index_b = find_target_index_b(b, current->value);
	cost.rb = target_index_b;
	cost.rrb = b->size - target_index_b;
	return (cost);
}
