/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:45:33 by welee             #+#    #+#             */
/*   Updated: 2024/07/28 18:18:52 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_stack_pop(t_stack *stack)
{
	t_node	*pop_node;
	int		value;

	if (!stack || stack->size == 0)
		return (INT_MIN);
	pop_node = stack->top;
	value = pop_node->value;
	if (stack->size == 1)
	{
		stack->top = NULL;
	}
	else
	{
		stack->top->prev->next = stack->top->next;
		stack->top->next->prev = stack->top->prev;
		stack->top = stack->top->next;
	}
	free(pop_node);
	stack->size--;
	return (value);
}
