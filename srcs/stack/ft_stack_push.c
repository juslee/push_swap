/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:44:26 by welee             #+#    #+#             */
/*   Updated: 2024/07/28 18:17:57 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stack_push(t_stack *stack, int value)
{
	t_node	*new_node;

	if (!stack)
		return ;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	if (stack->size == 0)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		stack->top = new_node;
	}
	else
	{
		new_node->next = stack->top;
		new_node->prev = stack->top->prev;
		stack->top->prev->next = new_node;
		stack->top->prev = new_node;
		stack->top = new_node;
	}
	stack->size++;
}
