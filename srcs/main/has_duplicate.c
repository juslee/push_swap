/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:12:46 by welee             #+#    #+#             */
/*   Updated: 2024/07/23 14:13:28 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	has_duplicate(t_stack *stack)
{
	t_stacknode	*outer;
	t_stacknode	*inner;

	outer = stack->top;
	while (outer && outer->next)
	{
		inner = outer->next;
		while (inner)
		{
			if (outer->value == inner->value)
				return (1);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (0);
}
