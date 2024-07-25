/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:04:47 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 20:04:52 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bottom;

	top = a->top->value;
	mid = a->top->next->value;
	bottom = a->top->next->next->value;
	if (top > mid && mid < bottom && top < bottom)
		sa(a);
	else if (top > mid && mid > bottom && top > bottom)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bottom && top > bottom)
		ra(a);
	else if (top < mid && mid > bottom && top < bottom)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bottom && top > bottom)
		rra(a);
}
