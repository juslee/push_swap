/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:26:57 by welee             #+#    #+#             */
/*   Updated: 2024/07/26 21:03:23 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stack_swap(t_stack *stack)
{
	int	temp;

	if (stack->size > 1)
	{
		temp = stack->top->value;
		stack->top->value = stack->top->next->value;
		stack->top->next->value = temp;
	}
}