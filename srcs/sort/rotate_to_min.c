/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:55:53 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 14:13:51 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

/**
 * @brief find min position
 *
 * @param a stack a
 * @return int min position
 */
static int	find_min_position(t_stack *a)
{
	t_node	*current;
	t_node	*min_node;
	int		min_position;
	int		i;

	current = a->top;
	min_node = current;
	min_position = 0;
	i = 0;
	while (current != a->top || i == 0)
	{
		if (current->value < min_node->value)
		{
			min_node = current;
			min_position = i;
		}
		current = current->next;
		i++;
	}
	return (min_position);
}

/**
 * @brief perform rotation
 *
 * @param a stack a
 * @param min_position min position
 */
static void	perform_rotation(t_stack *a, int min_position)
{
	int	rotate_count;

	if (min_position <= (a->size / 2))
	{
		rotate_count = min_position;
		while (rotate_count-- > 0)
			ra(a);
	}
	else
	{
		rotate_count = a->size - min_position;
		while (rotate_count-- > 0)
			rra(a);
	}
}

/**
 * @brief rotate stack a to the minimum value
 *
 * @param a stack a
 */
void	rotate_to_min(t_stack *a)
{
	int	min_position;

	if (a->size < 2)
		return ;
	min_position = find_min_position(a);
	perform_rotation(a, min_position);
}
