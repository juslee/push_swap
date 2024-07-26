/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:14:15 by welee             #+#    #+#             */
/*   Updated: 2024/07/26 21:03:04 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_sorted(t_stack *a)
{
	t_node	*current;

	if (!a || a->size < 2)
		return (1);
	current = a->top;
	while (current->next != a->top)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
