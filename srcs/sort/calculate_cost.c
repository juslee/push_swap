/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:14:21 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 14:12:21 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "libft.h"

/**
 * @brief find max value in stack b
 *
 * @param b stack b
 * @return int max value in stack b
 */
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

/**
 * @brief find index of max value in stack b
 *
 * @param b stack b
 * @param max_value max value in stack b
 * @return int index of max value in stack b
 */
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

/**
 * @brief find best fit index in stack b
 *
 * @param b stack b
 * @param value value of element in a
 * @return int index of best fit element in b
 */
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
		if ((current->value <= value)
			&& (best_fit == NULL || current->value > best_fit->value))
		{
			best_fit = current;
			best_fit_index = index;
		}
		current = current->next;
		index++;
	}
	return (best_fit_index);
}

/**
 * @brief find best index to move element from a to b
 *
 * @param b stack b
 * @param value value of element in a
 * @return int index of best fit element in b
 */
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

/**
 * @brief calculate cost of moving element from a to b
 *
 * @param a stack a
 * @param b stack b
 * @param index_a index of element in stack a
 * @return t_cost cost of moving element from a to b
 */
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
