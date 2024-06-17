/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:55:56 by welee             #+#    #+#             */
/*   Updated: 2024/06/17 12:49:36 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rb.c
 * @brief Shift up all elements of stack b by 1.
 */

#include "operations.h"

/**
 * @brief Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 *
 * @param b stack b
 */
void	rb(t_stack *b)
{
	t_list	*first;
	t_list	*last;

	if (b->size < 2)
		return ;
	first = b->top;
	last = b->top;
	while (last->next)
		last = last->next;
	b->top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}
