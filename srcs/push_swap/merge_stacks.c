/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:27:55 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 23:18:11 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_stacks(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		if (a->top->value > b->top->value)
		{
			pa(a, b);
		}
		else
		{
			ra(a);
		}
	}
}
