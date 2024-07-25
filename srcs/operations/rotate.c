/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:28:30 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 19:40:08 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rotate(t_stack *stack)
{
	t_stacknode	*top_node;
	t_stacknode	*bottom_node;

	if (stack->size < 2)
		return ;
	top_node = stack->top;
	bottom_node = stack->bottom;
	stack->top = top_node->next;
	stack->top->prev = NULL;
	bottom_node->next = top_node;
	top_node->prev = bottom_node;
	top_node->next = NULL;
	stack->bottom = top_node;
}
