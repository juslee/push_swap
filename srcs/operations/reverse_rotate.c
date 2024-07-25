/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:29:16 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 19:40:52 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	reverse_rotate(t_stack *stack)
{
	t_stacknode	*top_node;
	t_stacknode	*bottom_node;

	if (stack->size < 2)
		return ;
	top_node = stack->top;
	bottom_node = stack->bottom;
	stack->bottom = bottom_node->prev;
	stack->bottom->next = NULL;
	top_node->prev = bottom_node;
	bottom_node->next = top_node;
	bottom_node->prev = NULL;
	stack->top = bottom_node;
}
