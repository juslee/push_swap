/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:50:30 by welee             #+#    #+#             */
/*   Updated: 2024/07/26 21:53:25 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	insertion_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	i;
	int	j;

	size = a->size;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size && b->size > 0)
		{
			if (b->top->value < a->top->value)
				pa(a, b);
			else
				ra(a);
			j++;
		}
		pb(a, b);
		i++;
	}
	while (b->size > 0)
		pa(a, b);
}
