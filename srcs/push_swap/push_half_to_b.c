/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_half_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:27:02 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 23:17:38 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap.h"

void	push_half_to_b(t_stack *a, t_stack *b, int *sorted, int size)
{
	int	mid;
	int	pushed;

	mid = size / 2;
	pushed = 0;
	while (pushed < mid)
	{
		if (a->top->value <= sorted[mid])
		{
			pb(a, b);
			pushed++;
		}
		else
		{
			ra(a);
		}
	}
}
