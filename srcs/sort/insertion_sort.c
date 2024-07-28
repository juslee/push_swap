/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:50:30 by welee             #+#    #+#             */
/*   Updated: 2024/07/28 17:51:58 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void		insertion_sort(t_stack *a, t_stack *b);
static void	move_min_to_top(t_stack *stack);
static void	move_to_top(t_stack *stack, int pos);

void	insertion_sort(t_stack *a, t_stack *b)
{
	while (a->size > 0)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
}

static void	move_min_to_top(t_stack *stack)
{
	t_node	*min_node;
	t_node	*current;
	int		min_pos;
	int		i;

	if (!stack || !stack->top)
		return ;
	min_node = stack->top;
	current = stack->top->next;
	min_pos = 0;
	i = 1;
	while (current != stack->top)
	{
		if (current->value < min_node->value)
		{
			min_node = current;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	move_to_top(stack, min_pos);
}

static void	move_to_top(t_stack *stack, int pos)
{
	if (pos <= stack->size / 2)
	{
		while (pos-- > 0)
			ra(stack);
	}
	else
	{
		pos = stack->size - pos;
		while (pos-- > 0)
			rra(stack);
	}
}
