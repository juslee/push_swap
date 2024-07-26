/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:51:18 by welee             #+#    #+#             */
/*   Updated: 2024/07/26 22:00:40 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	find_min(t_stack *stack, int count)
{
	t_node	*current;
	int		min;
	int		i;

	if (stack->size == 0)
		return (INT_MAX);
	current = stack->top;
	min = current->value;
	i = 0;
	while (i < count && i < stack->size)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
		i++;
	}
	return (min);
}

void	sort_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (a->top->value <= find_min(a, 2))
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	if (b->size == 2 && b->top->value < b->top->next->value)
		sb(b);
	while (b->size > 0)
		pa(a, b);
}
