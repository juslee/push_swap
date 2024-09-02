/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:24:14 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 14:04:36 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief rotate stack
 *
 * @param stack stack
 */
void	ft_stack_rotate(t_stack *stack)
{
	if (stack->size > 1)
		stack->top = stack->top->next;
}
