/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:05:16 by welee             #+#    #+#             */
/*   Updated: 2024/06/17 12:51:20 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rrb.c
 * @brief Shift down all elements of stack b by 1.
 */

#include "operations.h"

/**
 * @brief Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 *
 * @param b stack b
 */
void	rrb(t_stack *b)
{
	t_list	*second_last;
	t_list	*last;

	if (b->size < 2)
		return ;
	second_last = b->top;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = b->top;
	b->top = last;
	write(1, "rrb\n", 4);
}
