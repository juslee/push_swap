/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:44:26 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 19:45:02 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stack_push(t_stack *stack, int value)
{
	t_stacknode	*node;

	node = malloc(sizeof(t_stacknode));
	if (!node)
		return ;
	node->value = value;
	node->next = stack->top;
	node->prev = NULL;
	if (stack->top)
		stack->top->prev = node;
	stack->top = node;
	if (stack->size == 0)
		stack->bottom = node;
	stack->size++;
}
