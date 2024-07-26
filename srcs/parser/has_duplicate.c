/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:12:46 by welee             #+#    #+#             */
/*   Updated: 2024/07/26 21:02:50 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	has_duplicates(t_stack *a)
{
	t_node	*current;
	t_node	*runner;

	if (!a || a->size < 2)
		return (0);
	current = a->top;
	while (current->next != a->top)
	{
		runner = current->next;
		while (runner != a->top)
		{
			if (runner->value == current->value)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}
