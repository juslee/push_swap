/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:43:07 by welee             #+#    #+#             */
/*   Updated: 2024/07/26 16:22:58 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stack_clear(t_stack *stack)
{
	while (stack->size > 0)
		ft_stack_pop(stack);
	free(stack);
}
