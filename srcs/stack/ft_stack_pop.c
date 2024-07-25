/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:45:33 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 19:45:47 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_stack_pop(t_stack *stack)
{
	t_stacknode	*node;
	int			value;

	if (stack->size == 0)
		return (0);
	node = stack->top;
	value = node->value;
	stack->top = node->next;
	if (stack->top)
		stack->top->prev = NULL;
	else
		stack->bottom = NULL;
	free(node);
	stack->size--;
	return (value);
}
