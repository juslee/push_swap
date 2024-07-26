/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:53:22 by welee             #+#    #+#             */
/*   Updated: 2024/07/26 21:15:46 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;
	int	top_value;

	size = a->size;
	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			top_value = a->top->value;
			if ((top_value >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}
