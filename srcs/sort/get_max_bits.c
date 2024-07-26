/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:54:47 by welee             #+#    #+#             */
/*   Updated: 2024/07/26 21:02:01 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	get_max_bits(t_stack *a)
{
	t_node	*current;
	int		max;
	int		bits;

	current = a->top;
	max = current->value;
	bits = 0;
	while (current->next != a->top)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	while (max)
	{
		bits++;
		max >>= 1;
	}
	return (bits);
}
