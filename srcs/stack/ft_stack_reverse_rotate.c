/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:25:42 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 14:04:31 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief reverse rotate stack
 *
 * @param stack stack
 */
void	ft_stack_reverse_rotate(t_stack *stack)
{
	if (stack->size > 1)
		stack->top = stack->top->prev;
}
